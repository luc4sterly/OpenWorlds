// 00434b70 FUN_00434b70 [Global]
// programa: gamma.dll

void __cdecl FUN_00434b70(int *param_1,int param_2)

{
  uint *this;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_a0;
  undefined4 local_9c;
  undefined ***local_98;
  undefined1 auStack_90 [52];
  undefined **local_5c [17];
  int local_18;
  undefined4 *local_14;
  
  this = FUN_0042c7f0();
  if (this == (uint *)0x0) {
    return;
  }
  FUN_0042ca50(this);
  if (param_2 != 0) {
    iVar1 = FUN_00403e80(param_1,param_2);
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)(**(code **)(*param_1 + 0x2e0))(param_1,iVar1,0);
      iVar3 = (**(code **)(*param_1 + 0x2ac))(param_1,iVar1);
      FUN_00424260(&local_18,puVar2,iVar3);
      FUN_00406490(&local_a0,&local_18);
      FUN_00404ed0(&local_18);
      local_14 = &local_9c;
      local_98 = local_5c;
      local_5c[0] = &PTR_LAB_0046f34c;
      FUN_00411ef0(local_14,0,(int)auStack_90);
      *local_14 = &PTR_FUN_00471860;
      *(undefined ***)local_14[1] = &PTR_LAB_0047186c;
      *(int *)(local_14[1] + 0x3c) = (int)local_14 + (0x40 - local_14[1]);
      FUN_004240f0(local_14 + 3,&local_a0,8);
      FUN_0042cb90(this,&local_9c,param_2);
      local_98[0xf] = (undefined **)((int)local_5c - (int)local_98);
      FUN_004231d0(&local_9c);
      FUN_004108d0(local_5c);
      FUN_00404ed0(&local_a0);
      (**(code **)(*param_1 + 0x300))(param_1,iVar1,puVar2,0);
    }
  }
  return;
}


