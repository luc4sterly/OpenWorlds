// 00451e60 FUN_00451e60 [Global]
// program: gamma.dll

int * __thiscall FUN_00451e60(void *this,uint param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  FUN_00407570(this);
  *(undefined2 *)((int)this + 4) = 0;
  for (; param_1 != 0; param_1 = param_1 / 10) {
    FUN_004095f0(this,1,(char)(param_1 % 10));
  }
  puVar2 = (undefined1 *)FUN_004089f0(this);
  puVar3 = (undefined1 *)FUN_004088e0(this);
  if ((puVar3 != puVar2) && (puVar2 = puVar2 + -1, puVar3 < puVar2)) {
    do {
      uVar1 = *puVar3;
      *puVar3 = *puVar2;
      *puVar2 = uVar1;
      puVar3 = puVar3 + 1;
      puVar2 = puVar2 + -1;
    } while (puVar3 < puVar2);
  }
  if (**(int **)this != 0) {
    *(short *)((int)this + 4) = (short)**(int **)this + -1;
  }
  return this;
}


