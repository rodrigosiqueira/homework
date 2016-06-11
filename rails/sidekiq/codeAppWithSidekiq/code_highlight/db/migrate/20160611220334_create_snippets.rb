class CreateSnippets < ActiveRecord::Migration[5.0]
  def change
    create_table :snippets do |t|
      t.string :language
      t.string :plain_code
      t.string :highlighted_code

      t.timestamps
    end
  end
end
