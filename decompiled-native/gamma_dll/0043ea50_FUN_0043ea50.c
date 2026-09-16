// 0043ea50 FUN_0043ea50 [Global]
// programa: gamma.dll

undefined4
FUN_0043ea50(int param_1,int *param_2,undefined4 *param_3,RECT *param_4,LPRECT param_5,
            undefined4 *param_6)

{
  int iVar1;
  tagRECT tStack_20;
  
  iVar1 = 0;
  if (param_1 != 4) {
    iVar1 = param_1 + 4;
  }
  *param_2 = iVar1;
  *param_3 = 0;
  GetClientRect(*(HWND *)(param_1 + 0x18),&tStack_20);
  param_4->left = 0;
  param_4->top = 0;
  param_4->right = tStack_20.right;
  param_4->bottom = tStack_20.bottom;
  CopyRect(param_5,param_4);
  *param_6 = 0x14;
  param_6[1] = 0;
  param_6[2] = *(undefined4 *)(param_1 + 0x18);
  param_6[3] = 0;
  param_6[4] = 0;
  (**(code **)(*(int *)*param_2 + 4))((int *)*param_2);
  return 0;
}


