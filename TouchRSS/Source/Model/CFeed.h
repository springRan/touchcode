//
//  CFeed.h
//  <#ProjectName#>
//
//  Created by Jonathan Wight on 09/20/09
//  Copyright 2009 toxicsoftware.com. All rights reserved.
//

#import <CoreData/CoreData.h>

@class CObjectTranscoder;

#pragma mark begin emogenerator forward declarations
@class CFeedEntry;
#pragma mark end emogenerator forward declarations

/** Feed */
@interface CFeed : NSManagedObject {
}

+ (CObjectTranscoder *)objectTranscoder;

#pragma mark begin emogenerator accessors

+ (NSString *)entityName;

// Attributes
@property (readwrite, retain) NSDate *lastChecked;
@property (readwrite, retain) NSString *subtitle;
@property (readwrite, retain) NSString *title;
@property (readwrite, retain) NSString *identifier;
@property (readwrite, retain) NSString *link;
@property (readwrite, retain) NSString *URL;

// Relationships
@property (readonly, retain) NSMutableSet *entries;
- (NSMutableSet *)entries;

#pragma mark end emogenerator accessors

@end