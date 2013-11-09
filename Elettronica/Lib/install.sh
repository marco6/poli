#!/bin/bash

# Ottengo i permessi di amministratore ed eseguo l'azione
NDIR=$(pwd | sed 's/[\\\/\&]/\\&/g')
sed "s/LibDir=LIB_DIR/LibDir=$NDIR/g" ./kicad.pro > /usr/share/kicad/template/kicad.pro
