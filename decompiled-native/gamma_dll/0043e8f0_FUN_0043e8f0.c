// 0043e8f0 FUN_0043e8f0 [Global]
// programa: gamma.dll

void __thiscall FUN_0043e8f0(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_10;
  
  puVar1 = *(undefined4 **)((int)this + 0x24);
  if (puVar1 == (undefined4 *)0x0) {
    return;
  }
  if (param_1 != 0) {
    iVar2 = (**(code **)*puVar1)(puVar1,&DAT_00466fe8,&local_10);
    if (iVar2 < 0) {
      return;
    }
    (**(code **)(*local_10 + 0x2c))
              (local_10,0xfffffffc,0,this,0,*(undefined4 *)((int)this + 0x1c),(int)this + 0x28);
    (**(code **)(*local_10 + 8))(local_10);
  }
  return;
}


