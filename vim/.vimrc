set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
source ~/.vundle.vimrc
call vundle#end()            " required
filetype plugin indent on    " required

" grep.vim
let Grep_Default_Options = '-IR'
let Grep_Skip_Files = '*.log *.db'
let Grep_Skip_Dirs = '.git node_modules'

" 컬러 스킴 사용
colorscheme dracula

" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

let g:nerdtree_sync_cursorline = 1
let g:NERDTreeHighlightCursorline = 1

source ~/.a.vimrc
set mouse=nic
autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o
