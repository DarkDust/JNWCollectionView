/*
 Copyright (c) 2013, Marc Haisenko, equinux AG. All rights reserved.
 Licensed under the MIT license <http://opensource.org/licenses/MIT>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 documentation files (the "Software"), to deal in the Software without restriction, including without limitation
 the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and
 to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial portions
 of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 IN THE SOFTWARE.
 */

#import <Foundation/Foundation.h>

// Where to insert the placeholder/marker and final item in a drop operation.
//
// This defines the intent in a multi-section collection. For example, the drop
// path section X item 0 could either mean to insert a new item in front of item
// 0 in section X, or it could mean to insert a new section in front of section X.
typedef NS_ENUM(NSInteger, JNWCollectionViewDropRelation) {
	// Drop before the drop path.
	//
	// If the item number is 0, the intent is to insert a new section (if the
	// layout and data support multiple sections).
	JNWCollectionViewDropRelationBefore = -1,
	// Drop at the drop path.
	JNWCollectionViewDropRelationAt = 0,
	// Drop after the drop path.
	//
	// If the item number is the last one in the section, the intent is to add a
	// new section after the current section (if the layout and data support
	// multiple sections).
	JNWCollectionViewDropRelationAfter = 1,
};

@interface JNWCollectionViewDropIndexPath : NSIndexPath

+ (instancetype)indexPathForItem:(NSInteger)item inSection:(NSInteger)section dropRelation:(JNWCollectionViewDropRelation)relation;

// The intended drop location in relation to the index path.
@property(readonly) JNWCollectionViewDropRelation jnw_relation;

// The index path item.
@property (nonatomic, readonly) NSInteger jnw_item;

// The index path section.
@property (nonatomic, readonly) NSInteger jnw_section;

@end