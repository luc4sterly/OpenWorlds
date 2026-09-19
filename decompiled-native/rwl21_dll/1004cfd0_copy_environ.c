// 1004cfd0 copy_environ [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    _copy_environ
   
   Library: Visual Studio 1998 Release */

undefined4 * __cdecl copy_environ(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int *piVar5;
  
  puVar3 = (undefined4 *)0x0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    piVar5 = param_1;
    while (iVar1 != 0) {
      piVar5 = piVar5 + 1;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
      iVar1 = *piVar5;
    }
    puVar3 = _malloc((int)puVar3 * 4 + 4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    iVar1 = *param_1;
    puVar2 = puVar3;
    while (iVar1 != 0) {
      pcVar4 = (char *)*param_1;
      param_1 = param_1 + 1;
      pcVar4 = __strdup(pcVar4);
      *puVar2 = pcVar4;
      puVar2 = puVar2 + 1;
      iVar1 = *param_1;
    }
    *puVar2 = 0;
  }
  return puVar3;
}


