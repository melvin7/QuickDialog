//                                
// Copyright 2011 ESCOZ Inc  - http://escoz.com
// 
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this 
// file except in compliance with the License. You may obtain a copy of the License at 
// 
// http://www.apache.org/licenses/LICENSE-2.0 
// 
// Unless required by applicable law or agreed to in writing, software distributed under
// the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF 
// ANY KIND, either express or implied. See the License for the specific language governing
// permissions and limitations under the License.
//

#import "QuickDialogStyleProvider.h"
#import "QuickDialogDataSource.h"
#import "QuickDialogTableDelegate.h"
#import <Foundation/Foundation.h>
#import "UIKit/UIKit.h"

@class QSection;
@class QElement;
@class QRootElement;

@interface QuickDialogTableView : UITableView {


@private
    __unsafe_unretained QuickDialogController *_controller;
    QRootElement *_root;
    id <UITableViewDataSource> quickformDataSource;
    id <UITableViewDelegate> quickformDelegate;
}

@property(nonatomic, strong) QRootElement *root;

@property(nonatomic, readonly) QuickDialogController *controller;

@property(nonatomic, assign) NSObject<QuickDialogStyleProvider> *styleProvider;
@property(nonatomic) BOOL deselectRowWhenViewAppears;


- (QuickDialogTableView *)initWithController:(QuickDialogController *)controller;

- (UITableViewCell *)cellForElement:(QElement *)element;

- (void)viewWillAppear;

- (void)reloadCellForElements:(QElement *)element, ... NS_REQUIRES_NIL_TERMINATION;

@end
