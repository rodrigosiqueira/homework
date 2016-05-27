class PersonalComputer
  attr_accessor :manufacturer,
                :model, :processor, :clock,
                :ram, :disk, :monitor,
                :colors, :vres, :hres, :net

  def initialize ( &block )
    instance_eval &block
  end
end

desktop = PersonalComputer.new do
  self.manufacturer = 'Acme'
  self.model = 'THX'
  self.processor = '986'
  self.clock = 9.6
  self.ram = 16
  self.monitor = 25
  self.colors = 16777216
  self.vres = 1280
  self.hres = 1600
  self.net = 't3'
end

p desktop
