// 00429482 FUN_00429482 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_00429482(undefined4 param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  undefined8 uVar2;
  uint local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  iVar1 = param_2;
  do {
    if (0x31 < local_20) {
      uVar2 = FUN_00429192(param_1,iVar1);
      local_1c = (undefined4)uVar2;
LAB_004294dc:
      return CONCAT44(param_2,local_1c);
    }
    iVar1 = local_20 * 4;
    if (in_EAX == *(int *)(&DAT_0043d888 + iVar1)) {
      uVar2 = FUN_00429192(param_1,iVar1);
      local_1c = (undefined4)uVar2;
      goto LAB_004294dc;
    }
    local_20 = local_20 + 1;
  } while( true );
}


