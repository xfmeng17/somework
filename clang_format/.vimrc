source ~/format.vim

" input settings
set number
set cursorline

" search settings
set hlsearch
set incsearch
set smartcase

" auto encoding detecting
set fileencodings=ucs-bom,utf-8-bom,utf-8,cp936,big5,gb18030,gbk,ucs
set termencoding=utf-8
set encoding=utf-8
let g:fencview_autodetect = 1

" set term encoding according to system locale
let &termencoding = substitute($LANG, "[a-zA-Z_-]*\.", "", "")

" locate project dir by BLADE_ROOT file
functio! FindProjectRootDir()
  let rootfile = findfile("BLADE_ROOT", ".;")
  " in project root dir
  if rootfile == "BLADE_ROOT"
  return ""
  endif
  return substitute(rootfile, "/BLADE_ROOT$", "", "")
  endfunction

" set path automatically
function! AutoSetPath()
let project_root = FindProjectRootDir()
  if project_root != ""
  exec "setlocal path+=" . project_root
  endif
endfunction
autocmd FileType {c,cpp} nested call AutoSetPath()

" auto insert gtest header inclusion for test source file
function! s:InsertHeaderGuard()
let fullname = expand("%:p")
let rootdir = FindProjectRootDir()
  if rootdir != ""
  let path = substitute(fullname, "^" . rootdir . "/", "", "")
  else
  let path = expand("%")
  endif
  let varname = toupper(substitute(path, "[^a-zA-Z0-9]", "_", "g"))

  " exec 'norm o#deif has('mouse')
  " set mouse=a
  " endif
  " fine ' . varname
  exec 'norm i// Copyright (c) 2020, Tencent Inc. All rights reserved.'
  exec 'norm oAuthor: regzhang <regzhang@tencent.com>'
  exec 'norm o'
  exec 'norm xx'
  exec 'norm o#ifndef ' . varname
  exec 'norm o#define ' . varname
  " exec 'norm o#pragma once'
  exec 'norm o'
  exec 'norm o'
  exec 'norm o'
  exec '$norm o#endif // ' . varname
  exec '$norm ggjwww'
endfunction
autocmd BufNewFile *.{h,hh.hxx,hpp} nested call <SID>InsertHeaderGuard()

map <C-K> :pyf ~/clang-format.py<cr>
imap <C-K> <c-o>:pyf ~/clang-format.py<cr>

function! Formatonsave()
  let l:formatdiff = 1
  pyf ~/clang-format.py
endfunction
autocmd BufWritePre *.h,*.hpp,*.cc,*.cpp call Formatonsave()
