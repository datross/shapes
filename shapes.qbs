import qbs
import qbs.Process
import qbs.File
import qbs.FileInfo
import qbs.TextFile
import "../../../libs/openFrameworksCompiled/project/qtcreator/ofApp.qbs" as ofApp

Project{
    property string of_root: "../../.."

    ofApp {
        name: { return FileInfo.baseName(path) }

        files: [
            'src/Action.cpp',
            'src/ActionFactory.cpp',
            'src/DependanteModifier.cpp',
            'src/DependanteSelectionModifier.cpp',
            'src/DeviceListener.cpp',
            'src/DreamBuilder.cpp',
            'src/FileManager.cpp',
            'src/Gesture.cpp',
            'src/GestureController.cpp',
            'src/Hud.cpp',
            'src/ModifierColor.cpp',
            'src/ModifierFactory.cpp',
            'src/ModifierRotation.cpp',
            'src/ModifierScale.cpp',
            'src/ModifierSoundSetter.cpp',
            'src/OscWrapper.cpp',
            'src/PostFx.cpp',
            'src/PostFxGlitch.cpp',
            'src/PostFxModifier.cpp',
            'src/Seed.cpp',
            'src/SeedConstant.cpp',
            'src/SeedFactory.cpp',
            'src/SeedSound.cpp',
            'src/SeedSoundEnvelope.cpp',
            'src/SeedSoundSpectrum.cpp',
            'src/SeedTime.cpp',
            'src/SeedTimeFunctor.cpp',
            'src/SelectionFactory.cpp',
            'src/SoundControler.cpp',
            'src/SoundListener.cpp',
            'src/SoundModifier.cpp',
            'src/Utility.cpp',
            'src/main.cpp',
            'src/modifier.cpp',
            'src/modifierSelection.cpp',
            'src/ofApp.cpp',
            'src/ofApp.h',
            'src/selection.cpp',
            'src/shape.cpp',
            'src/view.cpp',
            'src/world.cpp',
        ]

        of.addons: [
            'ofxAbletonLive',
            'ofxFft',
            'ofxLeapMotion2',
            'ofxMask',
            'ofxOsc',
            'ofxPostGlitch',
            'ofxSvg',
            'ofxMidi',
        ]

        // additional flags for the project. the of module sets some
        // flags by default to add the core libraries, search paths...
        // this flags can be augmented through the following properties:
        of.pkgConfigs: []       // list of additional system pkgs to include
        of.includePaths: []     // include search paths
        of.cFlags: []           // flags passed to the c compiler
        of.cxxFlags: []         // flags passed to the c++ compiler
        of.linkerFlags: []      // flags passed to the linker
        of.defines: []          // defines are passed as -D to the compiler
                                // and can be checked with #ifdef or #if in the code

        // other flags can be set through the cpp module: http://doc.qt.io/qbs/cpp-module.html
        // eg: this will enable ccache when compiling
        //
        // cpp.compilerWrapper: 'ccache'

        Depends{
            name: "cpp"
        }

        // common rules that parse the include search paths, core libraries...
        Depends{
            name: "of"
        }

        // dependency with the OF library
        Depends{
            name: "openFrameworks"
        }
    }

    references: [FileInfo.joinPaths(of_root, "/libs/openFrameworksCompiled/project/qtcreator/openFrameworks.qbs")]
}
