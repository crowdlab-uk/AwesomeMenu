//
//  AwesomeMenu.h
//  AwesomeMenu
//
//  Created by Levey on 11/30/11.
//  Copyright (c) 2011 Levey & Other Contributors. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AwesomeMenuItem.h"

@protocol AwesomeMenuDelegate;

#define AWESOMEMENU_EXPANDING @"AwesomeMenuExpanding"
#define AWESOMEMENU_CLOSING @"AwesomeMenuClosing"

@interface AwesomeMenu : UIView <AwesomeMenuItemDelegate> {
    
    NSArray *_menusArray;
    NSUInteger _flag;
    NSTimer *_timer;
    AwesomeMenuItem *_addButton;
    
    __unsafe_unretained id<AwesomeMenuDelegate> _delegate;
    BOOL _isAnimating;
}
@property (nonatomic, copy) NSArray *menusArray;
@property (nonatomic, getter = isExpanding) BOOL expanding;
@property (nonatomic, assign) id<AwesomeMenuDelegate> delegate;

@property (nonatomic, retain) UIImage *image;
@property (nonatomic, retain) UIImage *highlightedImage;
@property (nonatomic, retain) UIImage *contentImage;
@property (nonatomic, retain) UIImage *highlightedContentImage;

@property (nonatomic, assign) CGFloat nearRadius;
@property (nonatomic, assign) CGFloat endRadius;
@property (nonatomic, assign) CGFloat farRadius;
@property (nonatomic, assign) CGPoint startPoint;
@property (nonatomic, assign) CGFloat timeOffset;
@property (nonatomic, assign) CGFloat rotateAngle;
@property (nonatomic, assign) CGFloat menuWholeAngle;
@property (nonatomic, assign) CGFloat expandRotation;
@property (nonatomic, assign) CGFloat closeRotation;

@property (assign, nonatomic) BOOL enabled;

- (id)initWithFrame:(CGRect)frame menus:(NSArray *)aMenusArray;

@end

@protocol AwesomeMenuDelegate <NSObject>
- (void)AwesomeMenu:(AwesomeMenu *)menu didSelectIndex:(NSInteger)idx;
- (void)awesomeMenu:(AwesomeMenu *)menu isAnimating:(BOOL)flag;

@end