//
//  GlobalMacro.h
//  ___PROJECTNAME___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//___COPYRIGHT___
//

#ifndef Qsend_GlobalMacro_h
#define Qsend_GlobalMacro_h

//判断是NSString 返回 该String 否则返回 @""
#define kIsString(str) [str isKindOfClass:[NSString class]] ? str : @""


//----------------------系统----------------------------
//获取系统版本
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define CurrentSystemVersion [[UIDevice currentDevice] systemVersion]

#define  Divide_Scale_Iphone5   1136/960

//是否是iOS 7 及 以上版本
#define iOS_Version_7  [[[UIDevice currentDevice] systemVersion] floatValue] > 7.0
//是否是iOS 8 及 以上版本
#define iOS_Version_8  [[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0
#define Is_iOS_Version_7  ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)?YES:NO
//是否是 iPhone5 屏幕尺寸
//#define IS_IPHONE_5 ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )568 ) < DBL_EPSILON )



//判断iphone4
#define IS_IPHONE_4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
//判断iphone5
#define IS_IPHONE_5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
//判断iphone6
#define IS_iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
//判断iphone6+  iPhone6 plus分辨率 标准模式分辨率为1242x2208，放大模式分辨率为1125x2001
#define IS_iPhone6Plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size)||CGSizeEqualToSize(CGSizeMake(1125, 2001), [[UIScreen mainScreen] currentMode].size) : NO)

//----------------------系统----------------------------
//获取设备版本
#define ipad  UI_USER_INTERFACE_IDIOM()==UIUserInterfaceIdiomPad
#define IdiomPhone  UI_USER_INTERFACE_IDIOM()==UIUserInterfaceIdiomPhone

//-------------------获取设备大小尺寸-------------------------
//获取 屏幕Size
//设备屏幕尺寸 屏幕Size
#define kSCREEN_SIZE      [[UIScreen mainScreen] bounds].size
#define SCREEN_HEIGHT    ([UIScreen mainScreen].bounds.size.height)
#define SCREEN_WIDTH    ([UIScreen mainScreen].bounds.size.width)
//获取 屏幕Frame
#define kScreen_Frame   [UIScreen mainScreen].applicationFrame
#define kScreen_CenterX  kScreen_Width/2
#define kScreen_CenterY  kScreen_Height/2

//获取状态栏Frame
#define kScreen_StatusBarFrame   [[UIApplication sharedApplication] statusBarFrame]


//获取中间内容高度（除去状态栏，UITabBar，UINavigationBar）
//#define kContent_Height [[UIScreen mainScreen] bounds].size.height-44-49-20


//应用尺寸(不包括状态栏,通话时状态栏高度不是20，所以需要知道具体尺寸)
#define kContent_Height   ([UIScreen mainScreen].applicationFrame.size.height)
#define kContent_Width    ([UIScreen mainScreen].applicationFrame.size.width)
#define kContent_Frame    (CGRectMake(0, 0 ,kContent_Width,kContent_Height))
#define kContent_CenterX  kContent_Width/2
#define kContent_CenterY  kContent_Height/2


//定义GCD的后台线程和主线程
//后台运行
#define BACK_GCD(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)

//主线程运行
#define MAIN_GCD(block) dispatch_async(dispatch_get_main_queue(),block)


//-------------------获取设备大小-------------------------


//----------------------颜色类---------------------------
// rgb颜色转换（16进制->10进制）
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]


//带有RGBA的颜色设置
#define COLOR(R, G, B, A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]

// 获取RGB颜色
#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define RGB(r,g,b) RGBA(r,g,b,1.0f)
//随机色
#define KRandomColor  RGBA(arc4random_uniform(255),  arc4random_uniform(255),  arc4random_uniform(255), 1.0)

//背景色
#define WXBACKGROUND_COLOR [UIColor colorWithRed:231.0/255.0 green:229.0/255.0 blue:240.0/255.0 alpha:1.0]

//清除背景色
#define CLEARCOLOR [UIColor clearColor]

#pragma mark - color functions
#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
//黑色
#define BLACKCOLOR [UIColor colorWithHexString:@"#2c2c2b"]

//灰色
#define GRAYCOLOR [UIColor colorWithHexString:@"#7f7d7a"]

//----------------------颜色类--------------------------




//----------------------App缓存目录--------------------------
//沙盒Documents目录
#define APP_DOC_DIR     [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject]
//沙盒Library目录
#define APP_LIB_DIR     [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) lastObject]
//沙盒Library下的cache目录
#define APP_LIB_CACHE_DIR  [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject]
//沙盒tmp下的cache目录,这个目录用于存放临时文件，保存应用程序再次启动过程中不需要的信息
#define APP_TMP_DIR        NSTemporaryDirectory()
//----------------------App缓存目录--------------------------



//----------------------图片----------------------------

//读取本地图片
#define LOADIMAGE(file,ext) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:ext]]

//定义UIImage对象
#define IMAGE(A) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:A ofType:nil]]

//定义UIImage对象
#define ImageNamed(_pointer) [UIImage imageNamed:[UIUtil imageName:_pointer]]

//建议使用前两种宏定义,性能高于后者


//可拉伸的图片

#define ResizableImage(name,top,left,bottom,right) [[UIImage imageNamed:name] resizableImageWithCapInsets:UIEdgeInsetsMake(top,left,bottom,right)]
#define ResizableImageWithMode(name,top,left,bottom,right,mode) [[UIImage imageNamed:name] resizableImageWithCapInsets:UIEdgeInsetsMake(top,left,bottom,right) resizingMode:mode]
//----------------------图片----------------------------

/**
 *  ARC  相关
 */
#define WEAKSELF __weak __typeof(self) weakSelf = self  
#define AFWEAKSELF __weak __typeof(&*self) weakSelf = self  // AFNetworking的写法__weak __typeof(&*self)weakSelf = self;这种写法不局限于某个viewcontroller


#endif
