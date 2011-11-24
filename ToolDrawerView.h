//
//  ToolDrawerView.m
//
//  Created by Ayal Spitz on 7/17/11.
//  Copyright 2011 Ayal Spitz. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum{
    kTopCorner = 1,
    kBottomCorner = -1
} ToolDrawerVerticalCorner;

typedef enum{
    kLeftCorner = 1,
    kRightCorner = -1
} ToolDrawerHorizontalCorner;

typedef enum{
    kHorizontally,
    kVertically
} ToolDrawerDirection;

typedef enum{
    kChevronDefault,
    kChevronSimple
} ToolDrawerChevronStyle;

@protocol ToolDrawerDelegate;

@interface ToolDrawerView : UIView {
    id<ToolDrawerDelegate> delegate;
    NSTimer *toolDrawerFadeTimer;
    
    UIColor *chevronColor;
    BOOL idleFade;

    CGPoint openPosition;
    CGPoint closePosition;

    CGAffineTransform positionTransform;
    
    UIButton *handleButton;
    UIImage *handleButtonImage;
    UIImage *handleButtonBlinkImage;
    NSTimer *handleButtonBlinkTimer;
    
    BOOL open;
}

@property (nonatomic, assign) id<ToolDrawerDelegate> delegate;

@property (nonatomic, retain) UIColor *chevronColor;

@property (assign) ToolDrawerHorizontalCorner horizontalCorner;
@property (assign) ToolDrawerVerticalCorner verticalCorner;
@property (assign) ToolDrawerDirection direction;
@property (assign) ToolDrawerChevronStyle chevronStyle;
@property (nonatomic, retain) UIButton *handleButton;

@property (assign) NSTimeInterval durationToFade;
@property (assign) NSTimeInterval perItemAnimationDuration;


- (id)initInVerticalCorner:(ToolDrawerVerticalCorner)vCorner
       andHorizontalCorner:(ToolDrawerHorizontalCorner)hCorner
                    moving:(ToolDrawerDirection)aDirection
                  idleFade:(BOOL)fade
              chevronStyle:(ToolDrawerChevronStyle)cStyle
              chevronColor:(UIColor *)cColor;

- (void)blinkTabButton;

- (UIButton *)appendItem:(NSString *)imageName;    
- (UIButton *)appendImage:(UIImage *)img;
- (void)appendButton:(UIButton *)button;

- (bool)isOpen;
- (void)open;
- (void)close;

@end

@protocol ToolDrawerDelegate <NSObject>
- (void)toolDrawerIsOpening:(ToolDrawerView *)toolDrawerView;
- (void)toolDrawerIsClosing:(ToolDrawerView *)toolDrawerView;
- (void)toolDrawerIsOpened:(ToolDrawerView *)toolDrawerView;
- (void)toolDrawerIsClosed:(ToolDrawerView *)toolDrawerView;
@end
