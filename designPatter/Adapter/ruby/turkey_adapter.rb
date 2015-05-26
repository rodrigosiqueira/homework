class TurkeyAdapter < Duck

  public

    @turkey

    def initialize (pTurkey)
      @turkey = pTurkey
    end

    def quack
      @turkey.gobble
    end

    def fly
      @turkey.fly
    end

end

