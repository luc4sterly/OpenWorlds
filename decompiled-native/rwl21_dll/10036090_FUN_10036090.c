// 10036090 FUN_10036090 [Global]
// program: RWL21.DLL

int FUN_10036090(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x110);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[0x10];
    (*(code *)*puVar2)(puVar2,*(undefined4 *)(param_1 + 0x108),puVar2 + 6,puVar2[1]);
    RwDamageCameraViewport(param_1,puVar2[6],puVar2[7],puVar2[8],puVar2[9]);
    puVar2[0xf] = 0;
    puVar2[0x10] = 0;
    puVar2 = puVar1;
  }
  *(undefined4 *)(param_1 + 0x110) = 0;
  return param_1;
}


