void write_edge(FILE *writer, ab g, int *ninv)
{
    if (g->sag != NULL)
    {
        fprintf(writer, "%d", g->valeur);
        fprintf(writer, " -> ");
        fprintf(writer, "%d\n", g->sag->valeur);
        write_edge(writer, g->sag, ninv);
    }
    else
    {
        fprintf(writer, "I%d [style=invis]\n", *ninv);
        fprintf(writer, "%d -> I%d [style=invis]\n", g->valeur, *ninv);
        (*ninv)++;
    }
    fprintf(writer, "I%d [style=invis]\n", *ninv);
    fprintf(writer, "%d -> I%d [style=invis]\n", g->valeur, *ninv);
    (*ninv)++;
    if (g->sad != NULL)
    {
        fprintf(writer, "%d", g->valeur);
        fprintf(writer, " -> ");
        fprintf(writer, "%d\n", g->sad->valeur);
        write_edge(writer, g->sad, ninv);
    }
    else
    {
        fprintf(writer, "I%d [style=invis]\n", *ninv);
        fprintf(writer, "%d -> I%d [style=invis]\n", g->valeur, *ninv);
        (*ninv)++;
    }
}

void view(ab g)
{
    FILE *writer = fopen("temp.gv", "w");
    int n = 0;
    fprintf(writer, "digraph mygraph {\n");
    write_edge(writer, g, &n);
    fprintf(writer, "}\n");
    fclose(writer);
    system("xdot temp.gv &");
}
