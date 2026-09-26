// 00401e75 FUN_00401e75 [Global]
// programa: gdkup.exe

undefined4 __thiscall FUN_00401e75(void *this,HWND param_1,uint param_2,short param_3)

{
  HINSTANCE hInstance;
  uint uVar1;
  HWND hWnd;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 uVar2;
  undefined8 uVar3;
  LPCSTR lpIconName;
  CHAR local_128 [256];
  int local_28;
  char *local_24;
  HICON local_20;
  undefined4 local_1c;
  uint local_14;
  
  local_14 = param_2;
  if (param_2 < 0x111) {
    if (1 < param_2) {
      if (param_2 < 3) {
        PostQuitMessage(0);
      }
      else if (param_2 == 0x110) {
        lpIconName = (LPCSTR)0x3e8;
        hInstance = (HINSTANCE)GetWindowLongA(param_1,-6);
        local_20 = LoadIconA(hInstance,lpIconName);
        if ((local_20 == (HICON)0x0) &&
           (uVar1 = FUN_00401b19(extraout_ECX,0xbe), (char)uVar1 == '\0')) {
          local_1c = 0;
        }
        else {
          local_1c = 1;
        }
        SetClassLongA(param_1,-0xe,(LONG)local_20);
        SendMessageA(param_1,0x80,1,(LPARAM)local_20);
        SendMessageA(param_1,0x80,0,(LPARAM)local_20);
      }
    }
  }
  else if (param_2 < 0x112) {
    if (param_3 == 2) {
      hWnd = GetDlgItem(param_1,0x69);
      ShowWindow(hWnd,5);
      DAT_0040b01c = 1;
    }
  }
  else if (0x400 < param_2) {
    if (param_2 < 0x402) {
      FUN_00401d52(this);
      FUN_00401c56();
    }
    else if (param_2 == 0x402) {
      uVar3 = FUN_00402998(this,(byte *)s_xdelta_patch_00408126);
      local_24 = (char *)uVar3;
      if (local_24 == (char *)0x0) {
        DeleteFileA(*(LPCSTR *)(DAT_0040b030 + DAT_0040b02c * 4 + -4));
        uVar2 = extraout_ECX_03;
      }
      else {
        local_24 = local_24 + 0xd;
        local_28 = FUN_00402a56(extraout_ECX_00,' ');
        uVar2 = extraout_ECX_01;
        if (local_28 != 0) {
          FUN_00402a6a(extraout_ECX_01,local_24);
          local_128[local_28 - (int)local_24] = '\0';
          DeleteFileA(local_128);
          uVar2 = extraout_ECX_02;
        }
      }
      if ((DAT_0040b01c == 0) && (DAT_0040b02c < DAT_0040b028)) {
        FUN_00401d52(uVar2);
      }
      FUN_00401c56();
    }
  }
  return 0;
}


