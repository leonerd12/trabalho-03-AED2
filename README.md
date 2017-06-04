# trabalho-03-AED2

Trabalho 03 - Índice e arquivos em disco

Componentes:
    * Leonardo Augusto
    * Maria Luisa
    * Henrique Wildes

Na hora de compilar o trabalho, use os seguintes comandos.

```sh
$ gcc -c arquivo.c
$ gcc -c arv.c
$ gcc main.c -o teste arquivo.o arv.o

$ gcc -c tad-aluno.c tad-vetor.c tad-arvore.c
$ gcc leitura.c -o main tad-aluno.o tad-vetor.o
```
Acredito que esse foi um dos erros que cometemos com o TAD. O certo é compilar
os módulos separadamente e depois juntá-los na hora de compilar o programa
principal.
