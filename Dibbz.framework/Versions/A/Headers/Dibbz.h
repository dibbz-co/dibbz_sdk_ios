//
//  Dibbz.h
//  Dibbz
//
//  Created by Rogerio Candeias on 3/24/14.
//  Copyright (c) 2014 Dibbz. All rights reserved.
//
//
//  If you need help integrating the Dibbz SDK contact us at:
//  help@dibbz.co
//
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <QuartzCore/QuartzCore.h>


@protocol DibbzDelegate <NSObject>

@required
/**
 * When using DibbzDelegate this signals that the SDK is
 * ready to display a reward.
 */
-(void)onRewardFetched;


/**
 * Called if the SDK will not be able to display a reward.
 */
-(void)onRewardNotAvailable;


/**
 * Called if the user has redeemed the Reward.
 */
-(void)onRewardRedeemed;


/**
 * Called if the user has not redeemed the Reward.
 */
-(void)onRewardDiscard;


/**
 * Called when the SDK has finished showing the Reward to the user.
 */
-(void)onRewardComplete;


@end



@interface Dibbz : UIViewController <CLLocationManagerDelegate>

@property (weak, nonatomic) CLLocationManager *locationManager;
@property (nonatomic, weak) id <DibbzDelegate> delegate;


/**
 * Returns an instance of the Dibbz SDK (as a singleton Class). You have to
 * call this method when starting your application, so that the
 * SDK can display the user's Reward as fast as possible.
 *
 * Remember to specify your API KEY so that the SDK and successfully identify your application.
 */
+(Dibbz *)getInstance:(NSString*)apikey;


/**
 * Generic method to get an instance of the Dibbz SDK anywhere in your application
 */
+(Dibbz *)getInstance;


/**
 * Main method to show a reward automatically. By calling this function the
 * SDK will display a reward asynchronously.
 */
-(void)showReward;


/**
 * Show a reward automatically and send an event ID. Using this function you can check
 * the Dibbz dashboard on statistic about redeem rations on different moments in your application
 *
 * Please pass a integer from 0 to 10.000
 */
-(void)showReward:(int)eventID;



/**
 * Check if there is a reward being processed or displayed.
 * True if the reward is being displayed. False if not.
 */
-(BOOL)isRewardActive;


/**
 * Get the SDK status (for your convenience).
 */
-(int)getStatus;



@end
