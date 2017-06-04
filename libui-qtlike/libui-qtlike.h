#ifndef LIBUIQTIZED_H
#define LIBUIQTIZED_H

#include<string>

#include "../libui/ui.h"

using namespace std;

namespace UI {

class Application
{
public:
    // Application(); // TODO: check if this exists in Qt
    Application(int argc, char *argv[]);
    int exec();
private:
    int returnCode{1};
};

class Action;

class Menu
{
public:
    Menu(const string label);
    void addAction(Action *action);
private:
    uiMenu* menu;
};

class MenuBar
{
public:
    MenuBar();
    Menu *addMenu(string label);
};

class MainWindow
{
public:
    MainWindow();
    ~MainWindow();
    MenuBar *getMenuBar();
    void show();
private:
    MenuBar *menuBar; // a dummy menubar: libui only has one
    uiWindow *mainWindow;
};

namespace Keyboard {
	// TODO: hex values and key list taken from Qt
    // should probably be replaced by the gtk or a more
    // free one

#define Modl static constexpr long
	struct Modifier {
		Modl None        = 0x00000000;
		Modl Shift       = 0x02000000;
		Modl Control     = 0x04000000;
        Modl Ctrl        = Control;
		Modl Alt         = 0x08000000;
		Modl Meta        = 0x10000000;
		Modl Keypad      = 0x20000000;
		Modl GroupSwitch = 0x40000000;
		// Do not extend the mask to include 0x01000000
		Modl Mask        = 0xfe000000; // was KeyboardModifierMask
	};
#undef Modl

#define Keyl static constexpr long
    struct Key {
        Keyl Escape = 0x01000000;                // misc keys
        Keyl Tab = 0x01000001;
        Keyl Backtab = 0x01000002;
        Keyl Backspace = 0x01000003;
        Keyl Return = 0x01000004;
        Keyl Enter = 0x01000005;
        Keyl Insert = 0x01000006;
        Keyl Delete = 0x01000007;
        Keyl Pause = 0x01000008;
        Keyl Print = 0x01000009;
        Keyl SysReq = 0x0100000a;
        Keyl Clear = 0x0100000b;
        Keyl Home = 0x01000010;                // cursor movement
        Keyl End = 0x01000011;
        Keyl Left = 0x01000012;
        Keyl Up = 0x01000013;
        Keyl Right = 0x01000014;
        Keyl Down = 0x01000015;
        Keyl PageUp = 0x01000016;
        Keyl PageDown = 0x01000017;
        Keyl Shift = 0x01000020;                // modifiers
        Keyl Control = 0x01000021;
        Keyl Meta = 0x01000022;
        Keyl Alt = 0x01000023;
        Keyl CapsLock = 0x01000024;
        Keyl NumLock = 0x01000025;
        Keyl ScrollLock = 0x01000026;
        Keyl F1 = 0x01000030;                // function keys
        Keyl F2 = 0x01000031;
        Keyl F3 = 0x01000032;
        Keyl F4 = 0x01000033;
        Keyl F5 = 0x01000034;
        Keyl F6 = 0x01000035;
        Keyl F7 = 0x01000036;
        Keyl F8 = 0x01000037;
        Keyl F9 = 0x01000038;
        Keyl F10 = 0x01000039;
        Keyl F11 = 0x0100003a;
        Keyl F12 = 0x0100003b;
        Keyl F13 = 0x0100003c;
        Keyl F14 = 0x0100003d;
        Keyl F15 = 0x0100003e;
        Keyl F16 = 0x0100003f;
        Keyl F17 = 0x01000040;
        Keyl F18 = 0x01000041;
        Keyl F19 = 0x01000042;
        Keyl F20 = 0x01000043;
        Keyl F21 = 0x01000044;
        Keyl F22 = 0x01000045;
        Keyl F23 = 0x01000046;
        Keyl F24 = 0x01000047;
        Keyl F25 = 0x01000048;                // F25 .. F35 only on X11
        Keyl F26 = 0x01000049;
        Keyl F27 = 0x0100004a;
        Keyl F28 = 0x0100004b;
        Keyl F29 = 0x0100004c;
        Keyl F30 = 0x0100004d;
        Keyl F31 = 0x0100004e;
        Keyl F32 = 0x0100004f;
        Keyl F33 = 0x01000050;
        Keyl F34 = 0x01000051;
        Keyl F35 = 0x01000052;
        Keyl Super_L = 0x01000053;                 // extra keys
        Keyl Super_R = 0x01000054;
        Keyl Menu = 0x01000055;
        Keyl Hyper_L = 0x01000056;
        Keyl Hyper_R = 0x01000057;
        Keyl Help = 0x01000058;
        Keyl Direction_L = 0x01000059;
        Keyl Direction_R = 0x01000060;
        Keyl Space = 0x20;                // 7 bit printable ASCII
        Keyl Any = Space;
        Keyl Exclam = 0x21;
        Keyl QuoteDbl = 0x22;
        Keyl NumberSign = 0x23;
        Keyl Dollar = 0x24;
        Keyl Percent = 0x25;
        Keyl Ampersand = 0x26;
        Keyl Apostrophe = 0x27;
        Keyl ParenLeft = 0x28;
        Keyl ParenRight = 0x29;
        Keyl Asterisk = 0x2a;
        Keyl Plus = 0x2b;
        Keyl Comma = 0x2c;
        Keyl Minus = 0x2d;
        Keyl Period = 0x2e;
        Keyl Slash = 0x2f;
        Keyl Key_0 = 0x30;
        Keyl Key_1 = 0x31;
        Keyl Key_2 = 0x32;
        Keyl Key_3 = 0x33;
        Keyl Key_4 = 0x34;
        Keyl Key_5 = 0x35;
        Keyl Key_6 = 0x36;
        Keyl Key_7 = 0x37;
        Keyl Key_8 = 0x38;
        Keyl Key_9 = 0x39;
        Keyl Colon = 0x3a;
        Keyl Semicolon = 0x3b;
        Keyl Less = 0x3c;
        Keyl Equal = 0x3d;
        Keyl Greater = 0x3e;
        Keyl Question = 0x3f;
        Keyl At = 0x40;
        Keyl A = 0x41;
        Keyl B = 0x42;
        Keyl C = 0x43;
        Keyl D = 0x44;
        Keyl E = 0x45;
        Keyl F = 0x46;
        Keyl G = 0x47;
        Keyl H = 0x48;
        Keyl I = 0x49;
        Keyl J = 0x4a;
        Keyl K = 0x4b;
        Keyl L = 0x4c;
        Keyl M = 0x4d;
        Keyl N = 0x4e;
        Keyl O = 0x4f;
        Keyl P = 0x50;
        Keyl Q = 0x51;
        Keyl R = 0x52;
        Keyl S = 0x53;
        Keyl T = 0x54;
        Keyl U = 0x55;
        Keyl V = 0x56;
        Keyl W = 0x57;
        Keyl X = 0x58;
        Keyl Y = 0x59;
        Keyl Z = 0x5a;
        Keyl BracketLeft = 0x5b;
        Keyl Backslash = 0x5c;
        Keyl BracketRight = 0x5d;
        Keyl AsciiCircum = 0x5e;
        Keyl Underscore = 0x5f;
        Keyl QuoteLeft = 0x60;
        Keyl BraceLeft = 0x7b;
        Keyl Bar = 0x7c;
        Keyl BraceRight = 0x7d;
        Keyl AsciiTilde = 0x7e;

        Keyl nobreakspace = 0x0a0;
        Keyl exclamdown = 0x0a1;
        Keyl cent = 0x0a2;
        Keyl sterling = 0x0a3;
        Keyl currency = 0x0a4;
        Keyl yen = 0x0a5;
        Keyl brokenbar = 0x0a6;
        Keyl section = 0x0a7;
        Keyl diaeresis = 0x0a8;
        Keyl copyright = 0x0a9;
        Keyl ordfeminine = 0x0aa;
        Keyl guillemotleft = 0x0ab;        // left angle quotation mark
        Keyl notsign = 0x0ac;
        Keyl hyphen = 0x0ad;
        Keyl registered = 0x0ae;
        Keyl macron = 0x0af;
        Keyl degree = 0x0b0;
        Keyl plusminus = 0x0b1;
        Keyl twosuperior = 0x0b2;
        Keyl threesuperior = 0x0b3;
        Keyl acute = 0x0b4;
        Keyl mu = 0x0b5;
        Keyl paragraph = 0x0b6;
        Keyl periodcentered = 0x0b7;
        Keyl cedilla = 0x0b8;
        Keyl onesuperior = 0x0b9;
        Keyl masculine = 0x0ba;
        Keyl guillemotright = 0x0bb;        // right angle quotation mark
        Keyl onequarter = 0x0bc;
        Keyl onehalf = 0x0bd;
        Keyl threequarters = 0x0be;
        Keyl questiondown = 0x0bf;
        Keyl Agrave = 0x0c0;
        Keyl Aacute = 0x0c1;
        Keyl Acircumflex = 0x0c2;
        Keyl Atilde = 0x0c3;
        Keyl Adiaeresis = 0x0c4;
        Keyl Aring = 0x0c5;
        Keyl AE = 0x0c6;
        Keyl Ccedilla = 0x0c7;
        Keyl Egrave = 0x0c8;
        Keyl Eacute = 0x0c9;
        Keyl Ecircumflex = 0x0ca;
        Keyl Ediaeresis = 0x0cb;
        Keyl Igrave = 0x0cc;
        Keyl Iacute = 0x0cd;
        Keyl Icircumflex = 0x0ce;
        Keyl Idiaeresis = 0x0cf;
        Keyl ETH = 0x0d0;
        Keyl Ntilde = 0x0d1;
        Keyl Ograve = 0x0d2;
        Keyl Oacute = 0x0d3;
        Keyl Ocircumflex = 0x0d4;
        Keyl Otilde = 0x0d5;
        Keyl Odiaeresis = 0x0d6;
        Keyl multiply = 0x0d7;
        Keyl Ooblique = 0x0d8;
        Keyl Ugrave = 0x0d9;
        Keyl Uacute = 0x0da;
        Keyl Ucircumflex = 0x0db;
        Keyl Udiaeresis = 0x0dc;
        Keyl Yacute = 0x0dd;
        Keyl THORN = 0x0de;
        Keyl ssharp = 0x0df;
        Keyl division = 0x0f7;
        Keyl ydiaeresis = 0x0ff;

        // International input method support (X keycode - 0xEE00, the
        // definition follows Qt/Embedded 2.3.7) Only interesting if
        // you are writing your own input method

        // International & multi-key character composition
        Keyl AltGr               = 0x01001103;
        Keyl Multi_key           = 0x01001120;  // Multi-key character compose
        Keyl Codeinput           = 0x01001137;
        Keyl SingleCandidate     = 0x0100113c;
        Keyl MultipleCandidate   = 0x0100113d;
        Keyl PreviousCandidate   = 0x0100113e;

        // Misc Functions
        Keyl Mode_switch         = 0x0100117e;  // Character set switch
        //Key_script_switch       = 0x0100117e;  // Alias for mode_switch

        // Japanese keyboard support
        Keyl Kanji               = 0x01001121;  // Kanji, Kanji convert
        Keyl Muhenkan            = 0x01001122;  // Cancel Conversion
        Keyl Henkan              = 0x01001123;  // Alias for Henkan_Mode
        Keyl Romaji              = 0x01001124;  // to Romaji
        Keyl Hiragana            = 0x01001125;  // to Hiragana
        Keyl Katakana            = 0x01001126;  // to Katakana
        Keyl Hiragana_Katakana   = 0x01001127;  // Hiragana/Katakana toggle
        Keyl Zenkaku             = 0x01001128;  // to Zenkaku
        Keyl Hankaku             = 0x01001129;  // to Hankaku
        Keyl Zenkaku_Hankaku     = 0x0100112a;  // Zenkaku/Hankaku toggle
        Keyl Touroku             = 0x0100112b;  // Add to Dictionary
        Keyl Massyo              = 0x0100112c;  // Delete from Dictionary
        Keyl Kana_Lock           = 0x0100112d;  // Kana Lock
        Keyl Kana_Shift          = 0x0100112e;  // Kana Shift
        Keyl Eisu_Shift          = 0x0100112f;  // Alphanumeric Shift
        Keyl Eisu_toggle         = 0x01001130;  // Alphanumeric toggle

        // Korean keyboard support
        //
        // In fact, many Korean users need only 2 keys, Key_Hangul and
        // Key_Hangul_Hanja. But rest of the keys are good for future.

        Keyl Hangul              = 0x01001131;  // Hangul start/stop(toggle)
        Keyl Hangul_Start        = 0x01001132;  // Hangul start
        Keyl Hangul_End          = 0x01001133;  // Hangul end, English start
        Keyl Hangul_Hanja        = 0x01001134;  // Start Hangul->Hanja Conversion
        Keyl Hangul_Jamo         = 0x01001135;  // Hangul Jamo mode
        Keyl Hangul_Romaja       = 0x01001136;  // Hangul Romaja mode
        Keyl Hangul_Jeonja       = 0x01001138;  // Jeonja mode
        Keyl Hangul_Banja        = 0x01001139;  // Banja mode
        Keyl Hangul_PreHanja     = 0x0100113a;  // Pre Hanja conversion
        Keyl Hangul_PostHanja    = 0x0100113b;  // Post Hanja conversion
        Keyl Hangul_Special      = 0x0100113f;  // Special symbols

        // dead keys (X keycode - 0xED00 to avoid the conflict)
        Keyl Dead_Grave          = 0x01001250;
        Keyl Dead_Acute          = 0x01001251;
        Keyl Dead_Circumflex     = 0x01001252;
        Keyl Dead_Tilde          = 0x01001253;
        Keyl Dead_Macron         = 0x01001254;
        Keyl Dead_Breve          = 0x01001255;
        Keyl Dead_Abovedot       = 0x01001256;
        Keyl Dead_Diaeresis      = 0x01001257;
        Keyl Dead_Abovering      = 0x01001258;
        Keyl Dead_Doubleacute    = 0x01001259;
        Keyl Dead_Caron          = 0x0100125a;
        Keyl Dead_Cedilla        = 0x0100125b;
        Keyl Dead_Ogonek         = 0x0100125c;
        Keyl Dead_Iota           = 0x0100125d;
        Keyl Dead_Voiced_Sound   = 0x0100125e;
        Keyl Dead_Semivoiced_Sound = 0x0100125f;
        Keyl Dead_Belowdot       = 0x01001260;
        Keyl Dead_Hook           = 0x01001261;
        Keyl Dead_Horn           = 0x01001262;

        // multimedia/internet keys - ignored by default - see QKeyEvent c'tor
        Keyl Back  = 0x01000061;
        Keyl Forward  = 0x01000062;
        Keyl Stop  = 0x01000063;
        Keyl Refresh  = 0x01000064;
        Keyl VolumeDown = 0x01000070;
        Keyl VolumeMute  = 0x01000071;
        Keyl VolumeUp = 0x01000072;
        Keyl BassBoost = 0x01000073;
        Keyl BassUp = 0x01000074;
        Keyl BassDown = 0x01000075;
        Keyl TrebleUp = 0x01000076;
        Keyl TrebleDown = 0x01000077;
        Keyl MediaPlay  = 0x01000080;
        Keyl MediaStop  = 0x01000081;
        Keyl MediaPrevious  = 0x01000082;
        Keyl MediaNext  = 0x01000083;
        Keyl MediaRecord = 0x01000084;
        Keyl MediaPause = 0x1000085;
        Keyl MediaTogglePlayPause = 0x1000086;
        Keyl HomePage  = 0x01000090;
        Keyl Favorites  = 0x01000091;
        Keyl Search  = 0x01000092;
        Keyl Standby = 0x01000093;
        Keyl OpenUrl = 0x01000094;
        Keyl LaunchMail  = 0x010000a0;
        Keyl LaunchMedia = 0x010000a1;
        Keyl Launch0  = 0x010000a2;
        Keyl Launch1  = 0x010000a3;
        Keyl Launch2  = 0x010000a4;
        Keyl Launch3  = 0x010000a5;
        Keyl Launch4  = 0x010000a6;
        Keyl Launch5  = 0x010000a7;
        Keyl Launch6  = 0x010000a8;
        Keyl Launch7  = 0x010000a9;
        Keyl Launch8  = 0x010000aa;
        Keyl Launch9  = 0x010000ab;
        Keyl LaunchA  = 0x010000ac;
        Keyl LaunchB  = 0x010000ad;
        Keyl LaunchC  = 0x010000ae;
        Keyl LaunchD  = 0x010000af;
        Keyl LaunchE  = 0x010000b0;
        Keyl LaunchF  = 0x010000b1;
        Keyl MonBrightnessUp = 0x010000b2;
        Keyl MonBrightnessDown = 0x010000b3;
        Keyl KeyboardLightOnOff = 0x010000b4;
        Keyl KeyboardBrightnessUp = 0x010000b5;
        Keyl KeyboardBrightnessDown = 0x010000b6;
        Keyl PowerOff = 0x010000b7;
        Keyl WakeUp = 0x010000b8;
        Keyl Eject = 0x010000b9;
        Keyl ScreenSaver = 0x010000ba;
        Keyl WWW = 0x010000bb;
        Keyl Memo = 0x010000bc;
        Keyl LightBulb = 0x010000bd;
        Keyl Shop = 0x010000be;
        Keyl History = 0x010000bf;
        Keyl AddFavorite = 0x010000c0;
        Keyl HotLinks = 0x010000c1;
        Keyl BrightnessAdjust = 0x010000c2;
        Keyl Finance = 0x010000c3;
        Keyl Community = 0x010000c4;
        Keyl AudioRewind = 0x010000c5; // Media rewind
        Keyl BackForward = 0x010000c6;
        Keyl ApplicationLeft = 0x010000c7;
        Keyl ApplicationRight = 0x010000c8;
        Keyl Book = 0x010000c9;
        Keyl CD = 0x010000ca;
        Keyl Calculator = 0x010000cb;
        Keyl ToDoList = 0x010000cc;
        Keyl ClearGrab = 0x010000cd;
        Keyl Close = 0x010000ce;
        Keyl Copy = 0x010000cf;
        Keyl Cut = 0x010000d0;
        Keyl Display = 0x010000d1; // Output switch key
        Keyl DOS = 0x010000d2;
        Keyl Documents = 0x010000d3;
        Keyl Excel = 0x010000d4;
        Keyl Explorer = 0x010000d5;
        Keyl Game = 0x010000d6;
        Keyl Go = 0x010000d7;
        Keyl iTouch = 0x010000d8;
        Keyl LogOff = 0x010000d9;
        Keyl Market = 0x010000da;
        Keyl Meeting = 0x010000db;
        Keyl MenuKB = 0x010000dc;
        Keyl MenuPB = 0x010000dd;
        Keyl MySites = 0x010000de;
        Keyl News = 0x010000df;
        Keyl OfficeHome = 0x010000e0;
        Keyl Option = 0x010000e1;
        Keyl Paste = 0x010000e2;
        Keyl Phone = 0x010000e3;
        Keyl Calendar = 0x010000e4;
        Keyl Reply = 0x010000e5;
        Keyl Reload = 0x010000e6;
        Keyl RotateWindows = 0x010000e7;
        Keyl RotationPB = 0x010000e8;
        Keyl RotationKB = 0x010000e9;
        Keyl Save = 0x010000ea;
        Keyl Send = 0x010000eb;
        Keyl Spell = 0x010000ec;
        Keyl SplitScreen = 0x010000ed;
        Keyl Support = 0x010000ee;
        Keyl TaskPane = 0x010000ef;
        Keyl Terminal = 0x010000f0;
        Keyl Tools = 0x010000f1;
        Keyl Travel = 0x010000f2;
        Keyl Video = 0x010000f3;
        Keyl Word = 0x010000f4;
        Keyl Xfer = 0x010000f5;
        Keyl ZoomIn = 0x010000f6;
        Keyl ZoomOut = 0x010000f7;
        Keyl Away = 0x010000f8;
        Keyl Messenger = 0x010000f9;
        Keyl WebCam = 0x010000fa;
        Keyl MailForward = 0x010000fb;
        Keyl Pictures = 0x010000fc;
        Keyl Music = 0x010000fd;
        Keyl Battery = 0x010000fe;
        Keyl Bluetooth = 0x010000ff;
        Keyl WLAN = 0x01000100;
        Keyl UWB = 0x01000101;
        Keyl AudioForward = 0x01000102; // Media fast-forward
        Keyl AudioRepeat = 0x01000103; // Toggle repeat mode
        Keyl AudioRandomPlay = 0x01000104; // Toggle shuffle mode
        Keyl Subtitle = 0x01000105;
        Keyl AudioCycleTrack = 0x01000106;
        Keyl Time = 0x01000107;
        Keyl Hibernate = 0x01000108;
        Keyl View = 0x01000109;
        Keyl TopMenu = 0x0100010a;
        Keyl PowerDown = 0x0100010b;
        Keyl Suspend = 0x0100010c;
        Keyl ContrastAdjust = 0x0100010d;

        Keyl LaunchG  = 0x0100010e;
        Keyl LaunchH  = 0x0100010f;

        Keyl TouchpadToggle = 0x01000110;
        Keyl TouchpadOn = 0x01000111;
        Keyl TouchpadOff = 0x01000112;

        Keyl MicMute = 0x01000113;

        Keyl Red = 0x01000114;
        Keyl Green = 0x01000115;
        Keyl Yellow = 0x01000116;
        Keyl Blue = 0x01000117;

        Keyl ChannelUp = 0x01000118;
        Keyl ChannelDown = 0x01000119;

        Keyl Guide    = 0x0100011a;
        Keyl Info     = 0x0100011b;
        Keyl Settings = 0x0100011c;

        Keyl MicVolumeUp   = 0x0100011d;
        Keyl MicVolumeDown = 0x0100011e;

        Keyl New      = 0x01000120;
        Keyl Open     = 0x01000121;
        Keyl Find     = 0x01000122;
        Keyl Undo     = 0x01000123;
        Keyl Redo     = 0x01000124;

        Keyl MediaLast = 0x0100ffff;

        // Keypad navigation keys
        Keyl Select = 0x01010000;
        Keyl Yes = 0x01010001;
        Keyl No = 0x01010002;

        // Newer misc keys
        Keyl Cancel  = 0x01020001;
        Keyl Printer = 0x01020002;
        Keyl Execute = 0x01020003;
        Keyl Sleep   = 0x01020004;
        Keyl Play    = 0x01020005; // Not the same as Key_MediaPlay
        Keyl Zoom    = 0x01020006;
        Keyl Exit    = 0x0102000a;

        // Device keys
        Keyl Context1 = 0x01100000;
        Keyl Context2 = 0x01100001;
        Keyl Context3 = 0x01100002;
        Keyl Context4 = 0x01100003;
        Keyl Call = 0x01100004;      // set absolute state to in a call (do not toggle state)
        Keyl Hangup = 0x01100005;    // set absolute state to hang up (do not toggle state)
        Keyl Flip = 0x01100006;
        Keyl ToggleCallHangup = 0x01100007; // a toggle key for answering, or hanging up, based on current call state
        Keyl VoiceDial = 0x01100008;
        Keyl LastNumberRedial = 0x01100009;

        Keyl Camera = 0x01100020;
        Keyl CameraFocus = 0x01100021;

        Keyl unknown = 0x01ffffff;
    };
#undef Keyl

	class KeySequence
    {
        public:
        KeySequence(long k) {}
    };

}

class Action
{
public:
	/**
     * @brief see the qt specification:  http://doc.qt.io/qt-4.8/qaction.html#MenuRole-enum
     */
    enum MenuRole
    {
		NoRole,
		TextHeuristicRole,
		ApplicationSpecificRole,
		AboutQtRole,
		AboutRole,
		PreferencesRole,
		QuitRole
    };

    Action(string label, MainWindow *window);
    string const text() {return label;};
	MenuRole getMenuRole() {return menuRole;}
	void setMenuRole(MenuRole role) {menuRole = role;}
	void setShortcuts(Keyboard::KeySequence k);

private:
    string label;
    MainWindow *window;
	MenuRole menuRole;
};

}

#endif // LIBUIQTIZED_H
