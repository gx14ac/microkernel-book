{
  description = "browseros";
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    { self
    , nixpkgs
    , flake-utils
    }:
    flake-utils.lib.eachDefaultSystem (system:
    let pkgs = nixpkgs.legacyPackages.${system}; in
    rec {
      formatter = pkgs.nixpkgs-fmt;
      devShell = pkgs.mkShell {
        project_NIX_PATH = nixpkgs;
        buildInputs = [
          pkgs.llvmPackages_15.clangUseLLVM
          pkgs.qemu
        ];
      };
    });
}
