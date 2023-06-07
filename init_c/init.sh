#!/bin/bash

set -e 

function repo_root() {
    local repo="$(git rev-parse --show-toplevel)"
    test ${repo##*/} = "C" || exit 1 
    echo -n ${repo}

}

PROGRAM_NAME=${1}
REPO="$(repo_root)"
PROGRAM_PATH="${REPO}/${PROGRAM_NAME}"
INIT_PATH="${REPO}/init_c"

if test -e ${PROGRAM_PATH}; then
	echo "${PROGRAM_PATH} already taken"
	exit 1
fi

mkdir ${PROGRAM_PATH}

sed "s/__SED__/${PROGRAM_NAME}.c test_${PROGRAM_NAME}.c/" ${INIT_PATH}/makefile > ${PROGRAM_PATH}/makefile
cp ${INIT_PATH}/test_sample.c ${PROGRAM_PATH}/test_${PROGRAM_NAME}.c
sed "s/__SED__/${PROGRAM_NAME}/" ${INIT_PATH}/sample.c > ${PROGRAM_PATH}/${PROGRAM_NAME}.c
