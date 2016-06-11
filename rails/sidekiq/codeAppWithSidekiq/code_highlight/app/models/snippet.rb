class Snippet < ApplicationRecord
  validates :language, :plain_code, presence: true
end
