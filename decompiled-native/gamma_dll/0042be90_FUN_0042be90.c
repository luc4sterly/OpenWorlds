// 0042be90 FUN_0042be90 [Global]
// program: gamma.dll

char * __thiscall FUN_0042be90(void *this,int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  uint *puVar3;
  char *pcVar4;
  char *local_30;
  undefined **local_2c;
  undefined1 *local_14;
  
  pcVar4 = (char *)((param_2 - param_1) * 0x7e07e07f);
  iVar1 = (param_2 - param_1) / 0x104;
  if (iVar1 != 0) {
    puVar3 = FUN_0044e010(iVar1 * 0x104);
    *(uint **)((int)this + 8) = puVar3;
    *(int *)this = iVar1;
    pcVar4 = *(char **)((int)this + 8);
    if (param_1 != param_2) {
      local_2c = &PTR_LAB_00471ff8;
      local_30 = pcVar4;
      do {
        pcVar2 = local_30;
        pcVar4 = (char *)0x0;
        if (local_30 != (char *)0x0) {
          *(undefined ***)local_30 = local_2c;
          local_14 = (undefined1 *)&local_30;
          pcVar4 = FUN_0044d6d0(local_30 + 4,(char *)(param_1 + 4),0xff);
          pcVar2[0x103] = '\0';
        }
        param_1 = param_1 + 0x104;
        local_30 = local_30 + 0x104;
        *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
      } while (param_1 != param_2);
    }
  }
  return pcVar4;
}


