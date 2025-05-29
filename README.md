# PhotoShop-Lite
文件处理工具
| 日期 | 日志 |
| :---: | :--- |
| <i><b>2025.5.12 | 1、初步学习使用qt |
| <i><b>2025.5.14 | 1、qt完成基础的按键布局设置<br>2、窗口背景的替换 <br>3、实现通过按键打开任意图片|
| <i><b>2025.5.18 | 1、对c语言源码加了一点注释便于之后得演示<br>2、正在尝试将c语言源码通过qt实现来完成后续任务|
| <i><b>2025.5.23 | 1、对c语言源码进行修改，准备今天下午的验收，项目完成度不高但是大作业完成度还是有的|
| <i><b>2025.5.27 | 1、修改部分文件，准备开始着手报告撰写及后续未完成任务的完成 <br>2、修改图片显示方式，原本的缩放会导致图片变形，现在为固定比例，居中显示 <br>3、基础代码移植，目前代码编译不报错<br>4、代码移植成功，目前代码已经可以完成相应的操作，接下来完成相应控件的编写 <br>5、按钮一为 打开图片文件并保存这个图片文件 按钮三为设置新文件的保存位置 并将这个路径记录下来 按钮二为实现中值滤波并重新显示新的图片|
| <i><b>2025.5.29 | 1、增加窗口完成后续功能，为在新的窗口中输入对应的系数并完成相应的转换 <br>2、2、实现在新窗口中输入相关参数实现图片的缩小，并在主窗口中再次显示新图片，但是存在bug实现从子窗口调用主窗口ui后，子窗口消失，感觉融入住窗口了，下一步修这个bug <br>3、<br>4、 <br>5、|




使用到的参考链接（5月27日看了报告文件后才知道需要收录这个文件）
https://blog.csdn.net/sinat_36420785/article/details/81218049
https://blog.csdn.net/keanight/article/details/79150637
https://blog.csdn.net/qq_33485434/article/details/80680506 qstring和string转化
https://blog.csdn.net/u012790503/article/details/119855465 槽函数相关探究
https://www.cnblogs.com/LifeoFHanLiu/p/9978425.html getOpenFileName  getSaveFileName
https://blog.csdn.net/jkjijijkv/article/details/119969325 弹出新窗口
https://blog.csdn.net/yanghz/article/details/135004353 Qt6.5类库详解：QTextBrowse  看完详解后发现这个并不是我想要的 
https://blog.csdn.net/qq_45652092/article/details/111183979 Qt中的Qlabel类（标签类）详解
<!-- https://blog.csdn.net/qq_14945437/article/details/98730805 Qt之QSlider介绍(属性设置、信号、实现滑块移动到鼠标点击位置) -->
https://blog.csdn.net/Sakuya__/article/details/105885764  QT 在子窗口中调用主窗口的UI