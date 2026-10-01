// 0043e230 FUN_0043e230 [Global]
// program: gamma.dll

undefined4
FUN_0043e230(int param_1,int *param_2,undefined4 *param_3,RECT *param_4,LPRECT param_5,
            undefined4 *param_6)

{
  int iVar1;
  tagRECT tStack_20;
  
  iVar1 = param_1;
  if (param_1 != 0) {
    iVar1 = param_1 + 8;
  }
  *param_2 = iVar1;
  *param_3 = 0;
  GetClientRect(*(HWND *)(param_1 + 0x1c),&tStack_20);
  param_4->left = 0;
  param_4->top = 0;
  param_4->right = tStack_20.right;
  param_4->bottom = tStack_20.bottom;
  CopyRect(param_5,param_4);
  *param_6 = 0x14;
  param_6[1] = 0;
  param_6[2] = *(undefined4 *)(param_1 + 0x1c);
  param_6[3] = 0;
  param_6[4] = 0;
  (**(code **)(*(int *)*param_2 + 4))((int *)*param_2);
  return 0;
}


