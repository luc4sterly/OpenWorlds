// 10021270 FUN_10021270 [Global]
// program: RWL21.DLL

undefined4 * FUN_10021270(char *param_1)

{
  undefined4 *puVar1;
  char *pcVar2;
  char local_400 [1024];
  
  puVar1 = FUN_10009ae0(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    pcVar2 = FUN_10043de0(param_1,&DAT_1005ad00,local_400);
    puVar1 = (undefined4 *)0x0;
    if (pcVar2 != (char *)0x0) {
      puVar1 = FUN_10009ae0(local_400);
    }
    if (puVar1 == (undefined4 *)0x0) {
      pcVar2 = FUN_10043de0(param_1,&DAT_1005acf8,local_400);
      puVar1 = (undefined4 *)0x0;
      if (pcVar2 != (char *)0x0) {
        puVar1 = FUN_10009ae0(local_400);
      }
      goto LAB_100212cf;
    }
  }
  else {
LAB_100212cf:
    if (puVar1 != (undefined4 *)0x0) goto LAB_10021317;
    pcVar2 = FUN_10043de0(param_1,&DAT_1005acf0,local_400);
    puVar1 = (undefined4 *)0x0;
    if (pcVar2 != (char *)0x0) {
      puVar1 = FUN_10009ae0(local_400);
    }
  }
  if (puVar1 != (undefined4 *)0x0) {
    return puVar1;
  }
  pcVar2 = FUN_10043de0(param_1,&DAT_1005ace8,local_400);
  puVar1 = (undefined4 *)0x0;
  if (pcVar2 != (char *)0x0) {
    puVar1 = FUN_10009ae0(local_400);
  }
LAB_10021317:
  if ((puVar1 == (undefined4 *)0x0) &&
     (pcVar2 = FUN_10043de0(param_1,&DAT_1005ace0,local_400), pcVar2 != (char *)0x0)) {
    puVar1 = FUN_10009ae0(local_400);
  }
  return puVar1;
}


