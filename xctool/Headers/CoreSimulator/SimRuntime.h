//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

typedef void (^CDUnknownFunctionPointerType)(void);

@interface SimRuntime : NSObject

+ (id)supportedRuntimes;
+ (id)supportedRuntimesByAlias;
+ (id)supportedRuntimesByIdentifier;

- (id)init;
- (id)initWithBundle:(id)arg1;
- (id)initWithPath:(id)arg1;

// properties
@property(copy) NSDictionary *aliases;
@property(readonly) BOOL available;
@property(copy) NSString *buildVersionString;
@property(retain) NSBundle *bundle;
@property(copy) NSDictionary *environment_extra;
@property(copy) NSString *identifier;
@property(nonatomic) void *libLaunchHostHandle;
@property unsigned int maxHostVersion;
@property unsigned int minHostVersion;
@property(copy) NSString *name;
@property(copy) NSString *platformPath;
@property(copy) NSDictionary *requiredHostServices;
@property(copy) NSString *root;
@property(copy) NSDictionary *supportedFeatures;
@property(copy) NSDictionary *supportedFeaturesConditionalOnDeviceType;
@property(copy) NSArray *supportedProductFamilyIDs;
@property unsigned int version;
@property(copy) NSString *versionString;

// getters
- (id)dyld_simPath;
- (id)environment;
- (id)platformRuntimeOverlay;
- (id)sampleContentPath;

// core
- (BOOL)isAvailableWithError:(id *)arg1;
- (BOOL)supportsDevice:(id)arg1;
- (BOOL)supportsDeviceType:(id)arg1;
- (BOOL)supportsFeature:(id)arg1;
- (BOOL)supportsFeatureConditionally:(id)arg1;
- (BOOL)verifyRuntime;

// others
- (void)createInitialContentPath:(id)arg1;
- (BOOL)createInitialContentPath:(id)arg1 error:(id *)arg2;

- (CDUnknownFunctionPointerType)launch_sim_bind_session_to_port;
- (CDUnknownFunctionPointerType)launch_sim_find_endpoint;
- (CDUnknownFunctionPointerType)launch_sim_getenv;
- (CDUnknownFunctionPointerType)launch_sim_register_endpoint;
- (CDUnknownFunctionPointerType)launch_sim_set_death_handler;
- (CDUnknownFunctionPointerType)launch_sim_spawn;
- (CDUnknownFunctionPointerType)launch_sim_waitpid;

@end

@interface SimRuntime (DVTAdditions)
+ (id)dvt_runtimeFromSDKRoot:(id)arg1;
@end


