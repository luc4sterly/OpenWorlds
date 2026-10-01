// 0043fa70 _Java_NET_worlds_scape_TextureSurface_nativeInit@16 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_TextureSurface_nativeInit_16
               (undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  HINSTANCE hInstance;
  LPVOID lpParam;
  tagRECT local_14;
  
                    /* 0x3fa70  307  _Java_NET_worlds_scape_TextureSurface_nativeInit@16 */
  FUN_0043f9d0();
  local_14.top = 0;
  local_14.left = 0;
  local_14.bottom = param_4;
  local_14.right = param_3;
  AdjustWindowRect(&local_14,0xc00000,0);
  lpParam = (LPVOID)0x0;
  hInstance = (HINSTANCE)FUN_0040c110();
  CreateWindowExA(0,s_TextureSurface_00477ed0,&DAT_00477eec,0xc00000,0,0,
                  local_14.right - local_14.left,local_14.bottom - local_14.top,(HWND)0x0,(HMENU)0x0
                  ,hInstance,lpParam);
  return;
}


