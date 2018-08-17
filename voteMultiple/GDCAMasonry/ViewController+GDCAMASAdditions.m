//
//  UIViewController+MASAdditions.m
//  Masonry
//
//  Created by Craig Siemens on 2015-06-23.
//
//

#import "ViewController+GDCAMASAdditions.h"

#ifdef MAS_VIEW_CONTROLLER

@implementation MAS_VIEW_CONTROLLER (MASAdditions)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

- (GDCAMASViewAttribute *)mas_topLayoutGuide {
    return [[GDCAMASViewAttribute alloc] initWithView:self.view item:self.topLayoutGuide layoutAttribute:NSLayoutAttributeBottom];
}
- (GDCAMASViewAttribute *)mas_topLayoutGuideTop {
    return [[GDCAMASViewAttribute alloc] initWithView:self.view item:self.topLayoutGuide layoutAttribute:NSLayoutAttributeTop];
}
- (GDCAMASViewAttribute *)mas_topLayoutGuideBottom {
    return [[GDCAMASViewAttribute alloc] initWithView:self.view item:self.topLayoutGuide layoutAttribute:NSLayoutAttributeBottom];
}

- (GDCAMASViewAttribute *)mas_bottomLayoutGuide {
    return [[GDCAMASViewAttribute alloc] initWithView:self.view item:self.bottomLayoutGuide layoutAttribute:NSLayoutAttributeTop];
}
- (GDCAMASViewAttribute *)mas_bottomLayoutGuideTop {
    return [[GDCAMASViewAttribute alloc] initWithView:self.view item:self.bottomLayoutGuide layoutAttribute:NSLayoutAttributeTop];
}
- (GDCAMASViewAttribute *)mas_bottomLayoutGuideBottom {
    return [[GDCAMASViewAttribute alloc] initWithView:self.view item:self.bottomLayoutGuide layoutAttribute:NSLayoutAttributeBottom];
}

#pragma clang diagnostic pop

@end

#endif
