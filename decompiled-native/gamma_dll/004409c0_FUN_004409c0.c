// 004409c0 FUN_004409c0 [Global]
// program: gamma.dll

void __thiscall FUN_004409c0(void *this,HWND param_1,HDC param_2)

{
  int iVar1;
  BOOL BVar2;
  int wDest;
  HDC local_10;
  
  iVar1 = (**(code **)(**(int **)((int)this + 0x30) + 0x18))(*(int **)((int)this + 0x30),0,0,0,0);
  if (iVar1 == 0) {
    BVar2 = GetClientRect(param_1,(LPRECT)((int)this + 0x50));
    if (BVar2 == 0) {
      FUN_0044d5a0(s_Failed_to_get_video_rect_00478288);
      FUN_0044d5a0(&DAT_004780c8);
      return;
    }
    iVar1 = (**(code **)(**(int **)((int)this + 0x1c) + 0x44))
                      (*(int **)((int)this + 0x1c),&local_10);
    if (iVar1 != 0) {
      FUN_0044d5a0(s_Offscreen_DC_failed__004782a4);
      FUN_0044d5a0(&DAT_004780c8);
      return;
    }
    wDest = *(int *)((int)this + 0x58) - *(int *)((int)this + 0x50);
    iVar1 = *(int *)((int)this + 0x5c) - *(int *)((int)this + 0x54);
    BVar2 = StretchBlt(param_2,0,0,wDest,iVar1,local_10,*(int *)((int)this + 0x50),
                       *(int *)((int)this + 0x54),wDest,iVar1,0xcc0020);
    (**(code **)(**(int **)((int)this + 0x1c) + 0x68))(*(int **)((int)this + 0x1c),local_10);
    if (BVar2 == 0) {
      FUN_0044d5a0(s_StretchBlt_failed__004782bc);
      FUN_0044d5a0(&DAT_004780c8);
    }
  }
  else {
    (**(code **)(**(int **)((int)this + 0x24) + 0x1c))(*(int **)((int)this + 0x24),0);
    *(undefined4 *)((int)this + 8) = 1;
  }
  return;
}


