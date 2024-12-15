const { getDefaultConfig } = require('metro-config');
const resolveForm = require('resolve-from');

const config = getDefaultConfig(__dirname);

config.resolver.resolveRequest = (context, moduleName, platform) => {
    if (moduleName.startsWith('event-target-shim') && context.originalModulePath.includes('react-native-webrtc')) {
        const eventTargetShimPath = resolveForm(context.originalModulePath, moduleName);

        return {
            type: 'sourceFile',
            filePath: eventTargetShimPath,
        };
    }

    return context.resolveRequest(context, moduleName, platform);
};

module.exports = config;


            "extraMavenRepos": [
              "../../node_modules/@notifee/react-native/android/libs"
            ]