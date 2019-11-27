//
//  xyyFMDBConfig.h
//  XYYFMDB
//
//  Created by biao on 2017/7/19.
//  Copyright © 2017年 Biao. All rights reserved.
//

#ifndef XYYFMDBConfig_h
#define XYYFMDBConfig_h

// 过期方法注释
#define XYYFMDBDeprecated(instead) NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, instead)

#define xyy_primaryKey @"xyy_id"
#define xyy_createTimeKey @"xyy_createTime"
#define xyy_updateTimeKey @"xyy_updateTime"

//keyPath查询用的关系，xyy_equal:等于的关系；xyy_contains：包含的关系.
#define xyy_equal @"Relation_Equal"
#define xyy_contains @"Relation_Contains"

#define xyy_complete_B void(^_Nullable)(BOOL isSuccess)
#define xyy_complete_I void(^_Nullable)(xyy_dealState result)
#define xyy_complete_A void(^_Nullable)(NSArray* _Nullable array)
#define xyy_changeBlock void(^_Nullable)(xyy_changeState result)

typedef NS_ENUM(NSInteger,xyy_changeState){//数据改变状态
    xyy_insert,//插入
    xyy_update,//更新
    xyy_delete,//删除
    xyy_drop//删表
};

typedef NS_ENUM(NSInteger,xyy_dealState){//处理状态
    xyy_error = -1,//处理失败
    xyy_incomplete = 0,//处理不完整
    xyy_complete = 1//处理完整
};

typedef NS_ENUM(NSInteger,xyy_sqliteMethodType){//sqlite数据库原生方法枚举
    xyy_min,//求最小值
    xyy_max,//求最大值
    xyy_sum,//求总和值
    xyy_avg//求平均值
};

typedef NS_ENUM(NSInteger,xyy_dataTimeType){
    xyy_createTime,//存储时间
    xyy_updateTime,//更新时间
};

/**
 封装处理传入数据库的key和value.
 */
extern NSString* _Nonnull xyy_sqlKey(NSString* _Nonnull key);
/**
 转换OC对象成数据库数据.
 */
extern NSString* _Nonnull xyy_sqlValue(id _Nonnull value);
/**
 根据keyPath和Value的数组, 封装成数据库语句，来操作库.
 */
extern NSString* _Nonnull xyy_keyPathValues(NSArray* _Nonnull keyPathValues);
/**
 直接执行sql语句;
 @tablename nil时以cla类名为表名.
 @cla 要操作的类,nil时返回的结果是字典.
 提示：字段名要增加xyy_前缀
 */
extern id _Nullable xyy_executeSql(NSString* _Nonnull sql,NSString* _Nullable tablename,__unsafe_unretained _Nullable Class cla);
/**
 自定义数据库名称.
 */
extern void xyy_setSqliteName(NSString*_Nonnull sqliteName);
/**
 删除数据库文件
 */
extern BOOL xyy_deleteSqlite(NSString*_Nonnull sqliteName);
/**
 设置操作过程中不可关闭数据库(即closeDB函数无效).
 默认是NO.
 */
extern void xyy_setDisableCloseDB(BOOL disableCloseDB);
/**
 手动关闭数据库.
 */
extern void xyy_closeDB();
/**
 设置调试模式
 @debug YES:打印调试信息, NO:不打印调试信息.
 */
extern void xyy_setDebug(BOOL debug);

/**
 事务操作.
 @return 返回YES提交事务, 返回NO回滚事务.
 */
extern void xyy_inTransaction(BOOL (^ _Nonnull block)());

/**
 清除缓存
 */
extern void xyy_cleanCache();

#endif /* XYYFMDBConfig_h */
