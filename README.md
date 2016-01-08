# Debug 模式与 Release 模式的区分

<br />
如果在 Swift 项目中区分 Debug 模式与 Release 模式，需要添加 `-DDEBUG`。（不推荐）

还有一种方法是通过 Preprocessor Macros (预处理宏命令) 来区分模式。

<br />

1.新建一个 `PreProcessorMacros.h` 文件，代码如下

```swift
#import <Foundation/Foundation.h>

@interface PreProcessorMacros : NSObject

#ifndef PreProcessorMacros_h
#define PreProcessorMacros_h

extern BOOL const DEBUG_BUILD;

#endif

@end


@implementation PreProcessorMacros

#ifdef DEBUG
    BOOL const DEBUG_BUILD = YES;
#else
    BOOL const DEBUG_BUILD = NO;
#endif

@end

```

<br />

2.在 Bridged Header: `#import "PreProcessorMacros.h"`
> 也可直接把步骤一的代码放进 Bridged Header

<br />

3.测试

```
if DEBUG_BUILD {
    print("It's Debug build")
} else {
    print("It's Release build")
}
```

**⌘⇧<** 进入下图可模式切换

![](https://raw.githubusercontent.com/Limon-O-O/DEBUGBUILD/master/images/switch.png)

<br />

## 原理

关键的代码在：
```
#ifdef DEBUG
    BOOL const DEBUG_BUILD = YES;
#else
    BOOL const DEBUG_BUILD = NO;
#endif
```
此处的 `DEBUG` 究竟来自哪？

进入 'Build Settings' -> 搜索 'Preprocessor Macros'，真相大白

![](https://raw.githubusercontent.com/Limon-O-O/DEBUGBUILD/master/images/PreprocessorMacros.png)

<br />
抽取于干货极多的：[Reader Submissions -
New Year's 2016](http://nshipster.com/new-years-2016/)  🍺
