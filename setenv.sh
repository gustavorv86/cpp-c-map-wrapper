#!/bin/bash

library_path=`readlink -f -- ./dist`

if [[ ${LD_LIBRARY_PATH} ]]; then
	if [[ ! `echo ${LD_LIBRARY_PATH} | grep ${library_path}` ]]; then
		export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${library_path}
	fi
else
	export LD_LIBRARY_PATH=${library_path}	
fi

echo "LD_LIBRARY_PATH = "${LD_LIBRARY_PATH}

