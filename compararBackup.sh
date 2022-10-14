#!/bin/sh

#criando copia de segurança
cd /home/$(whoami)/Trabalho
tar -cvf /home/$(whoami)/backupTrabalhoSeguranca.tar.gz ./*

#Criando e guardando as chaves
cd /home/$(whoami)
chaveBkp=$(sha256sum backupTrabalho.tar.gz | awk '{print $1}')
chaveBkpSeguranca=$(sha256sum backupTrabalhoSeguranca.tar.gz | awk '{print $1}')

echo
echo Backup Completo e chaves de segurança criadas
echo

#Comparando as chaves
echo  $chaveBkp
echo  $chaveBkpSeguranca
if [ $chaveBkp = $chaveBkpSeguranca ];
then
echo chaves iguais
else
echo chaves *Diferentes*

#caso as chavese sejam diferentes:
#Deleta o diretorio alterado e volta o original
cd /home/$(whoami)
rm -r Trabalho
mkdir Trabalho
tar -xvf backupTrabalho.tar.gz -C Trabalho

#Avisa por email que esse procedimento foi feito
sendemail -f christian.marinho@icen.ufpa.br \
 -t christiandejesus23@gmail.com \
 -s cupijo.ufpa.br:587 \
 -u "Alteração nos Arquivos do Site" \
 -m "Foi detectada uma alteração nos arquivos do site, as medidas ja foram tomadas" \
 -xu christian.marinho@icen.ufpa.br -xp Chris1997
fi
