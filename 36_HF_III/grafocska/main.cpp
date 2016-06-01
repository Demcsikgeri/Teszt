#include <stdio.h>

int main()
{
    FILE *f=fopen("grafocska.gv","w+");
    fprintf(f,"digraph finite_state_machine {\r\n");
	fprintf(f,"rankdir=LR;\r\n");
	fprintf(f,"size=\"8,5\"\r\n");
    fprintf(f,"node [shape = doublecircle]; LR_0 LR_3 LR_4 LR_8;\r\n");
	fprintf(f,"node [shape = circle];\r\n");
	fprintf(f,"LR_0 -> LR_2 [ label = \"SS(B)\" ];\r\n");
	fprintf(f,"LR_0 -> LR_1 [ label = \"SS(S)\" ];\r\n");
	fprintf(f,"LR_1 -> LR_3 [ label = \"S($end)\" ];\r\n");
	fprintf(f,"LR_2 -> LR_6 [ label = \"SS(b)\" ];\r\n");
	fprintf(f,"LR_2 -> LR_5 [ label = \"SS(a)\" ];\r\n");
	fprintf(f,"LR_2 -> LR_4 [ label = \"S(A)\" ];\r\n");
	fprintf(f,"LR_5 -> LR_7 [ label = \"S(b)\" ];\r\n");
	fprintf(f,"LR_5 -> LR_5 [ label = \"S(a)\" ];\r\n");
	fprintf(f,"LR_6 -> LR_6 [ label = \"S(b)\" ];\r\n");
	fprintf(f,"LR_6 -> LR_5 [ label = \"S(a)\" ];\r\n");
	fprintf(f,"LR_7 -> LR_8 [ label = \"S(b)\" ];\r\n");
	fprintf(f,"LR_7 -> LR_5 [ label = \"S(a)\" ];\r\n");
	fprintf(f,"LR_8 -> LR_6 [ label = \"S(b)\" ];\r\n");
	fprintf(f,"LR_8 -> LR_5 [ label = \"S(a)\" ];\r\n");
    fprintf(f,"}\r\n");
    fflush(f);
    fclose(f);
    return 0;
}
