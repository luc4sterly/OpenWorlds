// 00411bf0 FUN_00411bf0 [Global]
// programa: gamma.dll

int * __thiscall FUN_00411bf0(void *this,LPCSTR param_1,byte param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  if (*(int *)((int)this + 0x24) != 0) {
    return (int *)0x0;
  }
  switch(param_2 & 0xfd) {
  case 8:
    pcVar5 = &DAT_0046f304;
    break;
  default:
    return (int *)0x0;
  case 0xc:
    pcVar5 = &DAT_0046f318;
    break;
  case 0x10:
  case 0x30:
    pcVar5 = &DAT_0046f2fc;
    break;
  case 0x11:
    pcVar5 = &DAT_0046f300;
    break;
  case 0x14:
  case 0x34:
    pcVar5 = &DAT_0046f310;
    break;
  case 0x15:
    pcVar5 = &DAT_0046f314;
    break;
  case 0x18:
    pcVar5 = &DAT_0046f308;
    break;
  case 0x1c:
    pcVar5 = &DAT_0046f31c;
    break;
  case 0x38:
    pcVar5 = &DAT_0046f30c;
    break;
  case 0x3c:
    pcVar5 = &DAT_0046f320;
  }
  piVar2 = FUN_00455020(param_1,pcVar5);
  *(int **)((int)this + 0x24) = piVar2;
  if (*(undefined4 **)((int)this + 0x24) != (undefined4 *)0x0) {
    if (((param_2 & 2) != 0) &&
       (iVar3 = FUN_004553b0(*(undefined4 **)((int)this + 0x24),0,2), iVar3 != 0)) {
      if (*(int *)((int)this + 0x24) != 0) {
        bVar1 = false;
        if ((*(uint *)((int)this + 0x10) < *(uint *)((int)this + 0x14)) &&
           (iVar3 = (**(code **)(*(int *)this + 0x30))(0xffffffff), iVar3 == -1)) {
          bVar1 = true;
        }
        if (!bVar1) {
          if (*(char *)((int)this + 0x40) != '\0') {
            uVar4 = FUN_00412340((int)this);
            if ((char)uVar4 == '\0') {
              return (int *)0x0;
            }
            *(undefined1 *)((int)this + 0x40) = 0;
          }
          FUN_00454eb0(*(undefined4 **)((int)this + 0x24));
          *(undefined4 *)((int)this + 0x24) = 0;
          *(undefined4 *)((int)this + 4) = 0;
          *(undefined4 *)((int)this + 8) = 0;
          *(undefined4 *)((int)this + 0xc) = 0;
          *(undefined4 *)((int)this + 0x14) = 0;
          *(undefined4 *)((int)this + 0x10) = *(undefined4 *)((int)this + 0x14);
          *(undefined4 *)((int)this + 0x18) = 0;
        }
      }
      return (int *)0x0;
    }
    return this;
  }
  return (int *)0x0;
}


