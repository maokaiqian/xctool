//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

typedef void (^CDUnknownBlockType)(void);

@class SimDeviceNotificationManager, SimDeviceSet, SimDeviceType, SimRuntime, SimServiceConnectionManager;

typedef NS_ENUM(long long, SimDeviceState) {
  SimDeviceStateCreating = 0,
  SimDeviceStateShutdown = 1,
  SimDeviceStateBooting = 2,
  SimDeviceStateBooted = 3,
  SimDeviceStateShuttingDown = 4,
};

@interface SimDevice : NSObject

// initializers
+ (id)createDeviceWithName:(NSString *)arg1 setPath:(NSString *)arg2 deviceType:(SimDeviceType *)arg3 runtime:(SimRuntime *)arg4;
+ (id)simDevice:(id)arg1 UDID:(id)arg2 deviceType:(SimDeviceType *)arg3 runtime:(SimRuntime *)arg4 state:(unsigned long long)arg5 connectionManager:(id)arg6 setPath:(NSString *)arg7;
+ (id)simDeviceAtPath:(id)arg1;

- (id)initDevice:(id)arg1 UDID:(id)arg2 deviceType:(SimDeviceType *)arg3 runtime:(SimRuntime *)arg4 state:(unsigned long long)arg5 connectionManager:(id)arg6 setPath:(NSString *)arg7;

// properties
@property(copy) NSUUID *UDID;
@property(readonly) BOOL available;
@property(retain) NSObject *bootstrapQueue;
@property(retain) SimServiceConnectionManager *connectionManager;
@property(retain) NSMachPort *deathTriggerPort;
@property(readonly, copy) NSString *descriptiveName;
@property(readonly) SimDeviceSet *deviceSet;
@property(retain) SimDeviceType *deviceType;
@property(retain, nonatomic) NSMachPort *hostSupportPort;
@property(readonly) NSArray *launchDaemonsPaths;
@property(readonly, copy) NSString *launchdJobName;
@property(readonly, copy) NSString *logPath;
@property(copy) NSString *name;
@property(retain) SimDeviceNotificationManager *notificationManager;
@property(retain) NSMutableDictionary *registeredServices;
@property(retain) SimRuntime *runtime;
@property(copy) NSString *setPath;
@property(retain, nonatomic) NSDistantObject *simBridgeDistantObject;
@property(retain, nonatomic) NSMachPort *simBridgePort;
@property unsigned long long state;
@property(retain) NSObject *stateVariableQueue;
@property(copy) NSDictionary *uiWindowProperties;

// getters
- (id)devicePath;
- (id)dataPath;
- (id)environment;
- (id)memoryWarningFilePath;
- (id)newDeviceNotification;
- (id)stateString;

// apps management
- (BOOL)applicationIsInstalled:(NSString *)bundleId type:(NSString **)arg2 error:(NSError **)error;
- (BOOL)installApplication:(NSURL *)appURL withOptions:(NSDictionary *)options error:(NSError **)error;
- (NSDictionary *)installedAppsWithError:(NSError **)error;
- (BOOL)isAvailableWithError:(NSError **)error;
- (void)launchApplicationAsyncWithID:(id)arg1 options:(id)arg2 completionHandler:(CDUnknownBlockType)arg3;
- (int)launchApplicationWithID:(id)arg1 options:(NSDictionary *)options error:(NSError **)error;
- (BOOL)uninstallApplication:(NSString *)bundleId withOptions:(NSDictionary *)options error:(NSError **)error;

// core
- (BOOL)addPhoto:(id)arg1 error:(id *)arg2;
- (BOOL)bootWithOptions:(id)arg1 error:(id *)arg2;
- (void)bootAsyncWithOptions:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (BOOL)clearTmpWithError:(id *)arg1;
- (BOOL)createLaunchdJobWithError:(id *)arg1 extraEnvironment:(id)arg2;
- (BOOL)eraseContentsAndSettingsWithError:(id *)arg1;
- (BOOL)openURL:(id)arg1 error:(id *)arg2;
- (BOOL)rename:(id)arg1 error:(id *)arg2;
- (void)renameAsync:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (BOOL)removeLaunchdJobWithError:(id *)arg1;
- (void)saveToDisk;
- (void)simulateMemoryWarning;
- (void)shutdownAsyncWithCompletionHandler:(CDUnknownBlockType)arg1;
- (BOOL)shutdownWithError:(id *)arg1;
- (BOOL)supportsFeature:(id)arg1;
- (void)upgradeAsyncToRuntime:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (BOOL)upgradeToRuntime:(id)arg1 error:(id *)arg2;


// other
+ (BOOL)isValidState:(unsigned long long)arg1;
- (id)createXPCNotification:(const char *)arg1;
- (id)createXPCRequest:(const char *)arg1;
- (BOOL)ensureLogPathsWithError:(id *)arg1;
- (void)eraseContentsAndSettingsAsyncWithCompletionHandler:(CDUnknownBlockType)arg1;
- (id)getenv:(id)arg1 error:(id *)arg2;
- (void)handleXPCNotification:(id)arg1;
- (void)handleXPCNotificationDeviceRenamed:(id)arg1;
- (void)handleXPCNotificationDeviceStateChanged:(id)arg1;
- (void)handleXPCNotificationDeviceUIWindowPropertiesChanged:(id)arg1;
- (void)handleXPCRequest:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestBoot:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestErase:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestGetenv:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestLookup:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestRegister:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestRename:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestRestore:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestShutdown:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestSpawn:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestUpdateUIWindow:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestUpgrade:(id)arg1 peer:(id)arg2;
- (void)launchdDeathHandlerWithDeathPort:(id)arg1;
- (unsigned int)lookup:(id)arg1 error:(id *)arg2;
- (unsigned long long)registerNotificationHandler:(CDUnknownBlockType)arg1;
- (unsigned long long)registerNotificationHandlerOnQueue:(id)arg1 handler:(CDUnknownBlockType)arg2;
- (BOOL)registerPort:(unsigned int)arg1 service:(id)arg2 error:(id *)arg3;
- (void)registerPortsWithLaunchd;
- (void)restoreContentsAndSettingsAsyncFromDevice:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (BOOL)restoreContentsAndSettingsFromDevice:(id)arg1 error:(id *)arg2;
- (id)saveStateDict;
- (BOOL)setKeyboardLanguage:(id)arg1 error:(id *)arg2;
- (void)simBridgeAsync:(CDUnknownBlockType)arg1;
- (void)simBridgeCommon:(CDUnknownBlockType)arg1;
- (void)simBridgeSync:(CDUnknownBlockType)arg1;
- (void)spawnAsyncWithPath:(id)arg1 options:(id)arg2 terminationHandler:(CDUnknownBlockType)arg3 completionHandler:(CDUnknownBlockType)arg4;
- (int)spawnWithPath:(id)arg1 options:(id)arg2 terminationHandler:(CDUnknownBlockType)arg3 error:(id *)arg4;
- (BOOL)startLaunchdWithDeathPort:(id)arg1 deathHandler:(CDUnknownBlockType)arg2 error:(id *)arg3;
- (BOOL)unregisterNotificationHandler:(unsigned long long)arg1 error:(id *)arg2;
- (void)updateAsyncUIWindowProperties:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (BOOL)updateUIWindowProperties:(id)arg1 error:(id *)arg2;
- (void)validateAndFixState;

- (unsigned int)_lookup:(id)arg1 error:(id *)arg2;
- (void)_sendUIWindowPropertiesToDevice;
- (BOOL)_shutdownWithError:(id *)arg1;
- (int)_spawnFromLaunchdWithPath:(id)arg1 options:(id)arg2 terminationHandler:(CDUnknownBlockType)arg3 error:(id *)arg4;
- (int)_spawnFromSelfWithPath:(id)arg1 options:(id)arg2 terminationHandler:(CDUnknownBlockType)arg3 error:(id *)arg4;

@end

