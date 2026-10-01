// 00452480 FUN_00452480 [Global]
// program: gamma.dll

int * __thiscall FUN_00452480(void *this,char *param_1,undefined2 param_2)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  
  FUN_00453820(this,param_1);
  *(undefined2 *)((int)this + 4) = param_2;
  pcVar1 = (char *)FUN_004088e0(this);
  pcVar2 = (char *)FUN_004089f0(this);
  for (; pcVar1 < pcVar2; pcVar1 = pcVar1 + 1) {
    *pcVar1 = *pcVar1 + -0x30;
  }
  if (**(int **)this != 0) {
    uVar3 = FUN_00453750(this,'\0',0xffffffff);
    if (uVar3 == 0xffffffff) {
      FUN_00408b80(this,0,'\0');
    }
    else if (uVar3 < **(int **)this - 1U) {
      FUN_004537e0(this,uVar3 + 1,0);
    }
  }
  return this;
}


