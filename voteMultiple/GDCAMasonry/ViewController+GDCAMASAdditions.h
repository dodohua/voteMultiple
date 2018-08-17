//
//  UIViewController+MASAdditions.h
//  Masonry
//
//  Created by Craig Siemens on 2015-06-23.
//
//

#import "GDCAMASUtilities.h"
#import "GDCAMASConstraintMaker.h"
#import "GDCAMASViewAttribute.h"

#ifdef MAS_VIEW_CONTROLLER

@interface MAS_VIEW_CONTROLLER (MASAdditions)

/**
 *	following properties return a new GDCAMASViewAttribute with appropriate UILayoutGuide and NSLayoutAttribute
 */
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *mas_topLayoutGuide NS_DEPRECATED_IOS(8.0, 11.0);
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *mas_bottomLayoutGuide NS_DEPRECATED_IOS(8.0, 11.0);
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *mas_topLayoutGuideTop NS_DEPRECATED_IOS(8.0, 11.0);
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *mas_topLayoutGuideBottom NS_DEPRECATED_IOS(8.0, 11.0);
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *mas_bottomLayoutGuideTop NS_DEPRECATED_IOS(8.0, 11.0);
@property (nonatomic, strong, readonly) GDCAMASViewAttribute *mas_bottomLayoutGuideBottom NS_DEPRECATED_IOS(8.0, 11.0);

@end

#endif
