//
//  NSString_Extensions.m
//  TouchHTTPD
//
//  Created by Jonathan Wight on 04/05/08.
//  Copyright (c) 2008 Jonathan Wight
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.
//

#import "NSString_Extensions.h"

@implementation NSString (NSString_Extensions)

- (BOOL)pathIsAppleDouble
{
NSString *theFilename = [self lastPathComponent];
return(theFilename.length >= 2 && [@"._" isEqualToString:[theFilename substringToIndex:2]]);
}

- (NSString *)pathByRemovingAppleDoublePrefix
{
NSString *theFilename = [self lastPathComponent];
if (theFilename.length < 2 || [@"._" isEqualToString:[theFilename substringToIndex:2]] == NO)
	return(self);
theFilename = [theFilename substringFromIndex:2];
NSString *thePath = [[self stringByDeletingLastPathComponent] stringByAppendingPathComponent:theFilename];
return(thePath);
}

@end