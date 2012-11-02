#import <Foundation/Foundation.h>
#import "LSEvent.h"

@interface LSStateMachine : NSObject
@property (nonatomic, strong, readonly) NSSet *states;
@property (nonatomic, strong, readonly) NSSet *events;
@property (nonatomic, strong) NSString *initialState;
- (void)addState:(NSString *)state;
- (void)when:(NSString *)eventName transitionFrom:(NSString *)from to:(NSString *)to;
- (LSEvent *)eventWithName:(NSString *)name;

- (void)before:(NSString *)eventName do:(LSStateMachineTransitionCallback)callback;
- (void)after:(NSString *)eventName do:(LSStateMachineTransitionCallback)callback;

- (NSString *)nextStateFrom:(NSString *)from forEvent:(NSString *)event;

@end

extern void * LSStateMachineDefinitionKey;

BOOL LSStateMachineTriggerEvent(id self, SEL _cmd);
void LSStateMachineInitializeInstance(id self, SEL _cmd);
void LSStateMachineInitializeClass(Class klass);
LSStateMachine * LSStateMachineSetDefinitionForClass(Class klass,void(^definition)(LSStateMachine *));