# vim
Learn and Update the Vim Setting


1. Clone the "source-insight-vim.git" and install it
 
 $ git clone https://github.com/geekan/source-insight-vim.git
 
 $ sudo chmod -R a+x source-insight-vim/
 
 $ source-insight-vim/install.sh
 
 
2. Apply fzf plugin
 
 $ git clone https://github.com/junegunn/fzf.vim.git
 
 $ sudo apt-get install fzf
 
 $ git clone --depth 1 https://github.com/junegunn/fzf.git ~/.fzf
 
 $ ~/.fzf/install
 
 
3. Setting Ag Command
 
 $ sudo apt-get install silversearcher-ag
 
 $ git clone https://github.com/ggreer/the_silver_searcher.git
 
 $ apt-get install -y automake pkg-config libpcre3-dev zlib1g-dev liblzma-dev
 
 $ ./build.sh
 
 $ sudo make install
 
 
4. Setting Rg Command
 
 $ sudo apt-get install ripgrep
 
 $ git clone https://github.com/BurntSushi/ripgrep.git
 
 $ cd ripgrep
 
 $ cargo build --release
 
 $ ./target/release/rg --version
 
 
5. Setting cscope Command
 
 $ apt-get install cscope -y
 
 $ chmod 755 mkcscope.sh
 
 $ mv mkcscope.sh /usr/local/bin
 
 
6. Load vim files
 
 $ git clone https://github.com/Lee-dong-ho/vim.git
 
 $ sudo mv .a.vimrc .vimrc .vundle.vimrc ~/.
 
 
7. .bashrc
 - Enter PS1 generator page
   https://scriptim.github.io/bash-prompt-generator/
 - Generate PS1 command suitable to you
