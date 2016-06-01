function pots_saver(FArray,FName,FValue_Max)

FArray=((FArray - min(min(FArray)))*(FValue_Max-2))/(max(max(FArray)) - min(min(FArray)))+2;

height=size(FArray,1);
width=size(FArray,2);

fid = fopen('pots.h', 'a');
fprintf(fid, 'extern const int pot_%s[maze_height][maze_width];\r\n',FName);
fclose(fid);

fid = fopen('pots.c', 'a');
fprintf(fid, 'const int pot_%s[maze_height][maze_width]={\r\n',FName);

for y = 1:height
    fprintf(fid,'{');
    for x = 1:width
        if (x==width)
            fprintf(fid,'%4.0f',FArray(y,x));
        else
            fprintf(fid,'%4.0f,',FArray(y,x));
        end
    end
    if (y==height)
        fprintf(fid,'}\r\n');
    else
        fprintf(fid,'},\r\n');
    end
end

fprintf(fid, '};\r\n');
fclose(fid);

surf(FArray, 'EdgeAlpha', '0.2');
axis ij;
colormap(jet)

print('-dpng',strcat('pot_',FName,'.png'));
end

