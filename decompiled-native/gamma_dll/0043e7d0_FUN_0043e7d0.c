// 0043e7d0 FUN_0043e7d0 [Global]
// program: gamma.dll

void __thiscall
FUN_0043e7d0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_10;
  
  *(undefined4 *)((int)this + 0x28) = param_1;
  *(undefined4 *)((int)this + 0x2c) = param_2;
  *(undefined4 *)((int)this + 0x30) = param_3;
  *(undefined4 *)((int)this + 0x34) = param_4;
  puVar1 = *(undefined4 **)((int)this + 0x24);
  if (puVar1 == (undefined4 *)0x0) {
    return;
  }
  iVar2 = (**(code **)*puVar1)(puVar1,&DAT_00466fa8,&local_10);
  if (iVar2 < 0) {
    return;
  }
  (**(code **)(*local_10 + 0x1c))(local_10,(int)this + 0x28,(int)this + 0x28);
  (**(code **)(*local_10 + 8))(local_10);
  return;
}


