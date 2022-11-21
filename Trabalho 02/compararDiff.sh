#!/bin/sh

#Comparando os diretorios
cd /home/$(whoami)/
comparacao=$(diff -r Trabalho BackupTrabalho)

if [ "$comparacao" = "" ];
then
echo diretorios iguais
else
echo diretorios *Diferentes*
echo $comparacao

#caso as chavese sejam diferentes:
#Deleta o diretorio alterado e volta o original
cd /home/$(whoami)/
rm -r Trabalho
cp -f -r BackupTrabalho /home/$(whoami)/Trabalho

#Avisa por email que esse procedimento foi feito
sendemail -f christian.marinho@icen.ufpa.br \
 -t christiandejesus23@gmail.com \
 -s cupijo.ufpa.br:587 \
 -u "Alteração nos Arquivos do Site" \
 -m "Foi detectada uma alteração nos arquivos do site, as medidas ja foram tomadas" \
 -xu christian.marinho@icen.ufpa.br -xp Chris1997
fi
