// 10002fe0 FUN_10002fe0 [Global]
// program: RWDLDD21.DLL

void FUN_10002fe0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_6c [26];
  undefined4 local_4;
  
  puVar2 = local_6c;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_6c[0] = 0x6c;
  local_6c[1] = 1;
  local_4 = 0x4000;
  (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,local_6c,0,&LAB_10001b40);
  if (DAT_10036038 != (int *)0x0) {
    (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
  }
  if (DAT_1003603c != DAT_10036038) {
    (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
  }
  return;
}


