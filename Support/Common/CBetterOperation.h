//
//  CBetterOperation.h
//  TouchCode
//
//  Created by Jonathan Wight on 4/28/09.
//  Copyright 2009 Small Society. All rights reserved.
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

#import <Foundation/Foundation.h>

@protocol CBetterOperationDelegate;

@interface CBetterOperation : NSOperation {
	id identifier;
	id userInfo;
	id <CBetterOperationDelegate> delegate;
	id result;
	NSError *error;
}

@property (readwrite, nonatomic, copy) id identifier;
@property (readwrite, nonatomic, retain) id userInfo;
@property (readwrite, nonatomic, assign) id <CBetterOperationDelegate> delegate;
@property (readwrite, retain) id result;
@property (readwrite, nonatomic, retain) NSError *error;

- (void)attainResult:(id)inResult;
- (void)failWithError:(NSError *)inError;

@end

#pragma mark -

@protocol CBetterOperationDelegate <NSObject>

@optional
- (void)operation:(CBetterOperation *)inOperation didAttainResult:(id)inResult;
- (void)operation:(CBetterOperation *)inOperation didFailWithError:(id)inError;

@end
