// 0040c2c0 FUN_0040c2c0 [Global]
// programa: gamma.dll

undefined4 __thiscall FUN_0040c2c0(void *this,int param_1,undefined4 param_2)

{
  LONG LVar1;
  DWORD DVar2;
  LONG LVar3;
  LONG LVar4;
  int iVar5;
  tagPOINT local_28;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  LVar1 = GetMessageTime();
  DVar2 = GetMessagePos();
  local_28.x = (LONG)(short)DVar2;
  local_28.y = (LONG)(short)(DVar2 >> 0x10);
  local_20 = local_28.x;
  local_1c = local_28.y;
  ScreenToClient(*(HWND *)this,&local_28);
  if ((DAT_00489274 != 0) || (DAT_00489278 != *(byte *)((int)this + 0x24))) goto LAB_0040c3da;
  if (*(byte *)((int)this + 0x24) == 0) {
    if ((local_20 != *(int *)((int)this + 0x28)) || (local_1c != *(int *)((int)this + 0x2c))) {
      iVar5 = 6;
      LVar3 = local_28.x;
      LVar4 = local_28.y;
LAB_0040c3c2:
      FUN_00416940(&DAT_0049f848,0,iVar5,LVar1,LVar3,LVar4);
    }
  }
  else {
    LVar4 = local_1c - *(int *)((int)this + 0x2c);
    LVar3 = local_20 - *(int *)((int)this + 0x28);
    if ((((local_20 < 0xa0) || (0x1e0 < local_20)) || (local_1c < 0x78)) || (0x168 < local_1c)) {
      local_1c = 0xf0;
      local_20 = 0x140;
      local_14 = 0xf0;
      local_18 = 0x140;
      SetCursorPos(0x140,0xf0);
    }
    if ((LVar3 != 0) || (LVar4 != 0)) {
      iVar5 = 7;
      goto LAB_0040c3c2;
    }
  }
  *(int *)((int)this + 0x28) = local_20;
  *(int *)((int)this + 0x2c) = local_1c;
LAB_0040c3da:
  if (param_1 != 6) {
    FUN_00416940(&DAT_0049f848,param_2,param_1,LVar1,local_28.x,local_28.y);
  }
  return 0;
}


