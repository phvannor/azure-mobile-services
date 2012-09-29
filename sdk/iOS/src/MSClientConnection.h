// ----------------------------------------------------------------------------
// Copyright (c) Microsoft Corporation. All rights reserved.
// ----------------------------------------------------------------------------
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>
#import "MSClient.h"


#pragma mark * Block Type Definitions


// Callback for successful connections. The |response| will be non-nil, but
// the |data| may or may not be nil depending on if the response had content.
typedef void (^MSSuccessBlock)(NSHTTPURLResponse *response, NSData *data);


#pragma  mark * MSClient Public Interface


// The |MSClientConnection| class is an implementation of the
// |NSURLConnectionDelegate| that provides either the response and response
// data or an error via block callbacks.
@interface MSClientConnection : NSObject <NSURLConnectionDataDelegate>


#pragma mark * Public Readonly Properties


// The client that created the connection
@property (nonatomic, strong, readonly)     MSClient *client;


#pragma  mark * Public Initializer Methods


// Initializes an |MSClientConnection| with the given client sends the given
// request. 
-(id) initWithRequest:(NSURLRequest *)request
           withClient:(MSClient *)client
            onSuccess:(MSSuccessBlock)onSuccess
              onError:(MSErrorBlock)onError;
@end
