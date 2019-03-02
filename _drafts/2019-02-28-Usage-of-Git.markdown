---
layout: post
title:  "Hello Blog"
date:   2019-02-22 15:26:51 -0800
category: Jekyll
tag: Environment
site.url: ~/Destop/myblog
---
# 安装和使用Jekyll
1. #### 安装ruby
mac Mojave自带ruby和gem，但是如果直接用gem下载的话会报权限错误。这里推荐的解决方案是用homebrew再下载一个ruby，这样子即有本地的也有新下载的。这个方案最直接便捷，还有使用rvm版本管理器的话，等什么时候方便再试试吧。
<br/>
下完之后，要往bash_profile加入以下这两句话，来找到新下载的ruby和gem。
<br/>
具体路径会在brew里面显示出来。
```
echo 'export PATH="/usr/local/opt/ruby/bin:$PATH"' >> ~/.bash_profile
echo 'export PATH="/usr/local/lib/ruby/gems/2.6.0/bin:$PATH"' >> ~/.bash_profile
```
这时候，再使用gem install jekyll命令，就可以成功下载jekyll了。

2. #### jekyll的使用
cd到你想要放置文件的地方，使用jekyll new myblog生成工作目录[快速指南](http://jekyllcn.com/docs/quickstart/)。此时会出现bundle找不到的错误。虽然没找到原因，但是我觉得很有可能是因为版本问题所以导致原来的bundle不能使用，这时候只需要使用gem重新下载bundle就可以了。
```
gem install bundler
```

3. #### Enjoy Jekyll !!!
这是你刚刚new出来的整个文件的框架。此时cd进入当前文件夹，再使用jekyll serve部署在本地服务器上，从而查看出来的效果。
<br/>
<img src="{{site.url}}/assets/file_frame.png" width="30%" alt="AltText" />
<br/>
整了好久还是不知道怎么[修改css的样式表](https://ddddxxx.github.io/2017/08/21/insert-retina-image-in-md/)从而实现将图片按比例缩小，这里先mark下来，先把后面的工作做完先。
<br/>
<p align="right"><font size="2" color="grey">Done at 02.22.2019</font></p>
